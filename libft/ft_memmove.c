/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:07:12 by aelharim          #+#    #+#             */
/*   Updated: 2016/11/24 15:19:01 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char	*str;

	str = (char*)malloc(sizeof(char) * n);
	if (str)
	{
		ft_memcpy(str, src, n);
		ft_memcpy(dest, str, n);
		free(str);
	}
	return (dest);
}
