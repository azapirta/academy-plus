/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw_map.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azapirta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:49:39 by azapirta          #+#    #+#             */
/*   Updated: 2016/03/31 16:58:20 by azapirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

void    init_struct(t_mod *data)
{
	data->rows = 0;
	data->columns = 0;
	data->max_z = 0;
	data->min_z = 0;
}

void    draw(t_mod *data)
{
	t_map   **matrix;

	data->m2 = get_initial_coords(data);
	get_min_max_z(data);
	map_center(data);
	control_height(data);
	matrix = get_isometric_coords(data);
	draw_between_points(data, matrix);
}

int     draw_matrix(t_mod *data)
{
	get_size(data);
	draw(data);
	show_usage(data);
	return (0);
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
