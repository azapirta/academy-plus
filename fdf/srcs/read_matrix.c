/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read_matrix.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azapirta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/31 15:50:29 by azapirta          #+#    #+#             */
/*   Updated: 2016/03/31 16:58:52 by azapirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

int     **add_content(int **matrix, t_mod *data, int *i)
{
	int p;
	int j;
	int k;

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


int     **add_new_row(t_mod *data)
{
	int i;
	int j;
	int **matrix;

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


int     **add_first_row(int fd, t_mod *data)
{
	char    *lines;

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

int     read_matrix(int fd, t_mod *data)
{
	char    *lines;
	int     i;
	int     col;

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
