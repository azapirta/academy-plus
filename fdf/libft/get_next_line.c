/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: azapirta <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/03/10 14:24:37 by azapirta          #+#    #+#             */
/*   Updated: 2016/03/10 14:24:55 by azapirta         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int  read_buff(int const fd, char **segment)
{
	char    *buff;
	int     ret;
	char    *new_file;

	buff = (char*)malloc(sizeof(*buff) * BUFF_SIZE + 1);
	if (!buff)
		return (-1);
	ret = read(fd, buff, BUFF_SIZE);
	if (ret > 0)
	{
		buff[ret] = '\0';
		new_file = ft_strjoin(*segment, buff);
		free(*segment);
		*segment = new_file;
	}
	free(buff);
	return (ret);
}

int         get_next_line(int const fd, char **line)
{
	static char     *text = NULL;
	char            *n_poz;
	int             result;

	if ((!(text) && (text = (char*)malloc(sizeof(*text))) == NULL) || !(line)
			|| BUFF_SIZE < 0 || fd < 0)
		return (-1);
	n_poz = ft_strchr(text, '\n');
	while (n_poz == NULL)
	{
		result = read_buff(fd, &text);
		if (result == 0)
		{
			if (ft_strlen(text) == 0)
				return (0);
			text = ft_strjoin(text, "\n");
		}
		if (result < 0)
			return (-1);
		else
			n_poz = ft_strchr(text, '\n');
	}
	*line = ft_strsub(text, 0, ft_strlen(text) - ft_strlen(n_poz));
	text = ft_strdup(n_poz + 1);
	return (1);
}
