/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azapirta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 13:13:49 by azapirta          #+#    #+#             */
/*   Updated: 2016/03/16 16:06:51 by azapirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef __FDF_H
# define __FDF_H
# include "mlx.h"
# include "libft.h"
# include "stdio.h"
# include <math.h>
# define WIDTH 1000
# define HEIGHT 1000
# define DEG30 0.52398776

typedef struct	s_map
{
	float		x;
	float		y;
	float		z;
}				t_map;

typedef struct	s_mod
{
	char		**content;
	int			rows; 
	int			columns;
	int			**matrix;
	void		*mlx;
	void		*win;
	int			line_size;
	t_map		**m2;
	int			x;
	int			y;
}				t_mod;

#endif
