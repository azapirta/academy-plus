/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azapirta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:13:49 by azapirta          #+#    #+#             */
/*   Updated: 2016/03/31 16:54:04 by azapirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "mlx.h"
# include <unistd.h>
# include <stdio.h>
# include "libft.h"
# include <math.h>
# define WIDTH 1000
# define HEIGHT 1000
# define DEG30 0.52398776

typedef struct  s_point
{
	float   x;
	float   y;
	float   z;
}               t_map;

typedef struct  s_env
{
	void        *mlx;
	void        *win;
	int         rows;
	int         columns;
	int         **matrix;
	t_map		**m2;
	int         error;
	char        **content;
	float       line_size;
	float       min_z;
	float       max_z;
	int         white;
}               t_mod;

void			control_height(t_mod *data);
void			modify_z(t_mod *data, int control);
void			map_center(t_mod *data);
void			get_min_max_z(t_mod *data);
t_map			**get_initial_coords(t_mod *data);
void			get_size(t_mod *data);
t_map			**get_isometric_coords(t_mod *data);
void			draw_line_axis(t_mod *data, t_map v, t_map v1);
void			draw_between_points(t_mod *data, t_map **matrix);
void			show_usage(t_mod *data);
int				key_hook(int keycode, t_mod *data);
void			init_struct(t_mod *data);
void			draw_map(t_mod *data);
void			draw(t_mod *data);
int				draw_matrix(t_mod *data);
int				**add_content(int **matrix, t_mod *data, int *i);
int				**add_new_row(t_mod *data);
int				**add_first_row(int fd, t_mod *data);
int				read_matrix(int fd, t_mod *data);

#endif
