/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/15 16:10:48 by aelharim          #+#    #+#             */
/*   Updated: 2016/11/29 15:10:12 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t index;
	size_t indexbis;

	index = 0;
	while (dst[index] && index < size)
		index++;
	if (size <= index)
		return (size + ft_strlen(src));
	indexbis = index;
	while (src[index - indexbis] && index < size - 1)
	{
		dst[index] = src[index - indexbis];
		index++;
	}
	if (indexbis < size)
		dst[index] = '\0';
	return (indexbis + ft_strlen(src));
}
