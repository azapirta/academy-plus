/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_space_remove.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/12 18:17:44 by rcrisan           #+#    #+#             */
/*   Updated: 2015/11/17 18:33:45 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_space_remove(char *str)
{
	int		i;

	i = 0;
	while (str[i])
		if (str[i] == ' ' || str[i] == '\t')
			ft_strcpy(str + i, str + i + 1);
		else
			i++;
	return (str);
}
