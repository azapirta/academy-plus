/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   compute_projections.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azapirta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:52:30 by azapirta          #+#    #+#             */
/*   Updated: 2016/03/31 16:58:31 by azapirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    draw_line_axis(t_mod *data, t_map v, t_map v1)
{
	float   t;
	float   step;
	float   x;
	float   y;

	step = 1 / (fmax(fabs(v1.x - v.x), fabs(v1.y - v.y)));
	t = 0;
	while (t < 1)
	{
		x = v.x + t * (v1.x - v.x);
		y = v.y + t * (v1.y - v.y);
		mlx_pixel_put(data->mlx, data->win, x, y, 0xFF0000);
		t = t + step;
	}
}

void    draw_between_points(t_mod *data, t_map **matrix)
{
	int i;
	int j;

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

t_map   **get_initial_coords(t_mod *data)
{
	t_map   **tmp;
	int     i;
	int     j;

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

void    get_size(t_mod *data)
{
	if (data->columns > 100)
		data->line_size = (WIDTH - 300) / data->columns;
	else
		data->line_size = (WIDTH - 600) / data->columns;
}

t_map       **get_isometric_coords(t_mod *data)
{
	t_map       **matrix;
	int         i;
	int         j;

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
