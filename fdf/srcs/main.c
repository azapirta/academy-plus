/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azapirta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:57:07 by azapirta          #+#    #+#             */
/*   Updated: 2016/03/19 16:30:37 by azapirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void        control_height(t_mod *data)
{
	int     i;  
	int     j;  
	float   k;  

	i = 0;
	k = 0;
	while (i < data->rows)
	{   
		j = 0;
		while (j < data->columns)
		{   
			if (data->m2[i][j].z < 0)
				k = data->m2[i][j].z * -1; 
			else
				k = data->m2[i][j].z;
			if (k >= 40) 
				data->m2[i][j].z /= 10; 
			else if (k >= 20) 
				data->m2[i][j].z /= 6;
			else
				data->m2[i][j].z /= 4;
			j++;
		}   
		i++;
	}   
}

void        modify_z(t_mod *data, int control)
{
	int i;
	int j;

	i = 0;
	while (i < data->rows)
	{   
		j = 0;
		while (j < data->columns)
		{   
			if (control == 1)
				data->m2[i][j].z *= 2;
			else if (control == -1) 
				data->m2[i][j].z /= 2;
			j++;
		}   
		i++;
	}   
}

void	map_center(t_mod *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->columns)
		{
			data->m2[i][j].x -= (data->columns / 2);
			data->m2[i][j].y -= (data->rows / 2);
			j++;
		}
		i++;
	}
}

//---------GET MIN/MAX COORDS---------

void	get_min_max_z(t_mod *data)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->columns)
		{
			if (data->m2[i][j].z > data->max_z)
				data->max_z = data->m2[i][j].z;
			if (data->m2[i][j].z < data->min_z)
				data->min_z = data->m2[i][j].z;
			j++;
		}
		i++;
	}
}

//---------GET INITIAL COORDS---------

t_map	**get_initial_coords(t_mod *data)
{
	t_map	**tmp;
	int		i;
	int		j;

	i = 0;
	tmp = (t_map**)malloc(sizeof(t_map*) * data->rows);
	while (i < data->rows)
	{
		j = 0;
		tmp[i] = (t_map*)malloc(sizeof(t_map) * data->columns);
		while (j < data->columns)
		{
			tmp[i][j].x = j;
			tmp[i][j].y = i;
			tmp[i][j].z = data->matrix[i][j];
			j++;
		}
		i++;
	}
	return (tmp);
}

void	get_size(t_mod *data)
{
	if (data->columns > 100)
		data->line_size = (WIDTH - 300) / data->columns;
	else
		data->line_size = (WIDTH - 600) / data->columns;
}

t_map		**get_isometric_coords(t_mod *data)
{
	t_map		**matrix;
	int			i;  
	int			j;  

	i = 0;
	matrix = (t_map**)malloc(sizeof(t_map*) * data->rows);
	while (i < data->rows)
	{   
		j = 0;
		matrix[i] = (t_map*)malloc(sizeof(t_map) * data->columns);
		while (j < data->columns)
		{   
			matrix[i][j].x = WIDTH / 2 + data->m2[i][j].x * data->line_size * \
							 cos(DEG30) - data->m2[i][j].y * \
							 data->line_size * cos(DEG30);
			matrix[i][j].y = HEIGHT / 2 + data->m2[i][j].x * data->line_size * \
							 sin(DEG30) + data->m2[i][j].y * data->line_size * \
							 sin(DEG30) - data->m2[i][j].z * data->line_size;
			matrix[i][j].z = data->m2[i][j].z;
			j++;
		}   
		i++;
	}   
	return (matrix);
}

void	draw_line_axis(t_mod *data, t_map v1, t_map v2)
{
	float	step;
	float	t;
	float	x;
	float	y;

	step = 1 / (fmax(fabs(v2.x - v1.x), fabs(v2.y - v1.y)));
	t = 0;
	while (t < 1)
	{
		x = v1.x + t * (v2.x - v1.x);
		y = v1.y + t * (v2.y - v2.y);
		mlx_pixel_put(data->mlx, data->win, x, y, 0xFF00FF);
		t += step;
	}
}

void	draw_between_points(t_mod *data, t_map **matrix)
{
	int	i;
	int	j;

	i = 0;
	while (i < data->rows)
	{
		j = 0;
		while (j < data->columns)
		{
			if (j < data->columns - 1)
				draw_line_axis(data, matrix[i][j], matrix[i][j + 1]);
			if (i < data->rows - 1)
				draw_line_axis(data, matrix[i][j], matrix[i + 1][j]);
			j++;
		}
		i++;
	}
}

void    show_usage(t_mod *data)
{
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFF0000, "Usage:");
	mlx_string_put(data->mlx, data->win, 70, 10, 0xFF0000, \
			"move the up and down arrows to change the color");
	mlx_string_put(data->mlx, data->win, 10, 40, 0xFF0000, \
			"Press ESC to close the program");
}

int     key_hook(int keycode, t_mod *data)
{
	if (keycode == 53) 
	{   
		mlx_destroy_window(data->mlx, data->win);
		exit(0);
	}   
	else if (keycode == 126)
	{   
		modify_z(data, 1); 
		draw_matrix(data);
	}   
	else if (keycode == 125)
	{   
		modify_z(data, -1);
		draw_matrix(data);
	}   
	return (0);
}

//-------------DRAW MAP---------------

void	init_struct(t_mod *data)
{
	data->rows = 0;
	data->columns = 0;
	data->max_z = 0;
	data->min_z = 0;
}

void    draw_map(t_mod *data)
{
	data->mlx = mlx_init();
	data->win = mlx_new_window(data->mlx, WIDTH, HEIGHT, "win");
	mlx_expose_hook(data->win, draw_matrix, data);
	mlx_key_hook(data->win, key_hook, data);
	mlx_loop(data->mlx);
	sleep(10);
}

void	draw(t_mod *data)
{
	int		i;
	int		j;
	t_map	**matrix;

	data->m2 = get_initial_coords(data);
	get_min_max_z(data);
	map_center(data);
	control_height(data);
	matrix = get_isometric_coords(data);
	draw_between_points(data, matrix);
	mlx_loop(data->mlx);
}

int		draw_matrix(t_mod *data)
{
	get_size(data);
	draw(data);
	show_usage(data);               
	return (0);
}

//-----------ADD CONTENT--------------

int		**add_content(int **matrix, t_mod *data, int *i)
{
	int	p;
	int	j;
	int	k;

	p = *i;
	matrix[p] = (int*)malloc(sizeof(int) * data->columns);
	j = 0;
	k = 0;
	while (data->content[k])
	{
		matrix[p][j] = ft_atoi(data->content[k]);
		k++;
		j++;
	}
	return (matrix);
}

//-----------ADD NEW ROW---------------

int		**add_new_row(t_mod *data)
{
	int	i;
	int	j;
	int	**matrix;

	i = 0;
	matrix = (int**)malloc(sizeof(int*) * data->rows);
	while (i < data->rows - 1)
	{
		matrix[i] = (int*)malloc(sizeof(int) * data->columns);
		j = 0;
		while (j <= data->columns)
		{
			matrix[i][j] = data->matrix[i][j];
			j++;
		}
		i++;
	}
	add_content(matrix, data, &i);
	return (matrix);
}

//------------ADD FIRST ROW--------------

int		**add_first_row(int fd, t_mod *data)
{
	char	*lines;

	get_next_line(fd, &lines);
	if (lines != NULL)
	{
		data->content = ft_strsplit(lines, ' ');
		while (data->content[data->columns] != '\0')
			data->columns++;
		data->rows++;
		data->matrix = add_new_row(data);
	}
	return (data->matrix);
}

//-------------READ MATRIX---------------

int		read_matrix(int fd, t_mod *data)
{
	char	*lines;
	int		i;
	int		col;

	data->content = NULL;
	i = 0;
	col = 0;
	data->matrix = add_first_row(fd, data);
	while (get_next_line(fd, &lines))
	{
		col = 0;
		data->content = ft_strsplit(lines, ' ');
		while (data->content[col] != '\0')
			col++;
		if (col != data->columns)
			return (-1);
		data->rows++;
		data->matrix = add_new_row(data);
	}
	return (1);
}

//---------------INT MAIN()--------------

int		main(int argc, char **argv)
{
	void	*mlx;
	void	*win;
	int		x;
	int		y;
	t_mod	data;
	int		fd;

	fd = open(argv[1], O_RDONLY);
	init_struct(&data);
	if (fd < 0)
	{
		perror(argv[1]);
		return (0);
	}
	read_matrix(fd, &data);
	draw(&data);
	close(fd);
}
