/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:09:41 by aelharim          #+#    #+#             */
/*   Updated: 2016/11/16 18:52:56 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strstr(const char *src, const char *tofind)
{
	int		i;
	int		j;
	int		y;

	i = 0;
	j = 0;
	y = 0;
	if (tofind[0] == '\0')
		return ((char*)src);
	while (src[i] != '\0')
	{
		y = i;
		j = 0;
		while (src[y] == tofind[j])
		{
			y++;
			j++;
			if (tofind[j] == '\0')
				return ((char*)&src[i]);
		}
		i++;
	}
	return (NULL);
}
