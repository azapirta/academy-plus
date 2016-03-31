/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azapirta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 12:57:07 by azapirta          #+#    #+#             */
/*   Updated: 2016/03/31 16:29:58 by azapirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/fdf.h"

//---------------INT MAIN()--------------

int		main(int argc, char **argv)
{
	t_mod	data;
	int		fd;

	printf("%d", argc);
	fd = open(argv[1], O_RDONLY);
	init_struct(&data);
	if (fd < 0)
	{
		perror(argv[1]);
		return (0);
	}
	read_matrix(fd, &data);
	draw_map(&data);
	close(fd);
}
