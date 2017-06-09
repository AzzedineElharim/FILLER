/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 15:01:23 by aelharim          #+#    #+#             */
/*   Updated: 2016/11/16 18:18:27 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	a;
	char	*str;

	a = (char)c;
	str = NULL;
	while (*s != '\0')
	{
		if (*s == a)
			str = (char*)s;
		s++;
	}
	if (*s == '\0' && (char)c == '\0')
		return ((char*)s);
	return (str);
}
