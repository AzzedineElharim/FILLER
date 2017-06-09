/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:47:00 by aelharim          #+#    #+#             */
/*   Updated: 2016/11/24 17:03:52 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *src, const char *tofind, size_t n)
{
	size_t	t;

	if (*tofind == '\0')
		return ((char *)src);
	t = ft_strlen(tofind);
	while (*src != '\0' && n-- >= t)
	{
		if (*src == *tofind && ft_memcmp(src, tofind, t) == 0)
			return ((char *)src);
		src++;
	}
	return (NULL);
}
