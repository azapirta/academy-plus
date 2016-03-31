/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_coords.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azapirta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:53:34 by azapirta          #+#    #+#             */
/*   Updated: 2016/03/31 16:58:42 by azapirta         ###   ########.fr       */
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

void    map_center(t_mod *data)
{
	int i;
	int j;

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

void    get_min_max_z(t_mod *data)
{
	int i;
	int j;

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

void    show_usage(t_mod *data)
{
	mlx_string_put(data->mlx, data->win, 10, 10, 0xFF0000, "Usage:");
	mlx_string_put(data->mlx, data->win, 70, 10, 0xFF0000, \
			"move the up and down arrows to change the color");
	mlx_string_put(data->mlx, data->win, 10, 40, 0xFF0000, \
			"Press ESC to close the program");
}
