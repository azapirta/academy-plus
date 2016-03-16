/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: rcrisan <marvin@42.fr>                     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/10/23 18:48:56 by rcrisan           #+#    #+#             */
/*   Updated: 2015/11/14 12:25:21 by rcrisan          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s1)
{
	size_t		i;
	char		*temp;
	size_t		sum;

	if (s1 == NULL)
		return (NULL);
	sum = ft_strlen(s1);
	temp = (char*)malloc(sizeof(*temp) * (sum + 1));
	if (temp == NULL)
		return (NULL);
	i = 0;
	while (i < sum)
	{
		temp[i] = s1[i];
		i++;
	}
	temp[i] = '\0';
	return (temp);
}
