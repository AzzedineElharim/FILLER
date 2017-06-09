/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 14:18:10 by aelharim          #+#    #+#             */
/*   Updated: 2016/11/11 14:33:10 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	char	*s1;
	char	*s2;
	size_t	i;

	if (n == 0 || dest == src)
		return (dest);
	s1 = (char *)src;
	s2 = (char *)dest;
	i = 0;
	while (i < n)
	{
		*s2 = *s1;
		s1++;
		s2++;
		i++;
	}
	return (dest);
}
