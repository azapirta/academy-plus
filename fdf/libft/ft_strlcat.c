/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 14:28:29 by rcrisan           #+#    #+#             */
/*   Updated: 2015/11/11 17:48:08 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t	i;
	size_t	j;
	size_t	aux;

	i = 0;
	j = 0;
	aux = ft_strlen(dst);
	if ((int)(size - ft_strlen(dst) - 1) < 0)
		return (ft_strlen(src) + size);
	while (dst[i])
		i++;
	while (j < (size - aux - 1))
	{
		dst[i] = src[j];
		i++;
		j++;
	}
	dst[i] = '\0';
	return (aux + ft_strlen(src));
}
