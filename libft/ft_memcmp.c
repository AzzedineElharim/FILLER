/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/11 15:50:41 by aelharim          #+#    #+#             */
/*   Updated: 2016/11/28 19:51:20 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_memcmp(const void *s1, const void *s2, size_t n)
{
	unsigned int	i;
	unsigned char	*ptr1;
	unsigned char	*ptr2;

	if ((s1 == NULL && s2 == NULL) || n == 0)
		return (0);
	ptr1 = (unsigned char*)s1;
	ptr2 = (unsigned char*)s2;
	i = 0;
	while (ptr1[i] == ptr2[i] && i < n)
	{
		if (i == (unsigned int)(n - 1) && (ptr1[i] == '\0' && ptr2[i] == '\0'))
			return (0);
		i++;
	}
	if (i == n)
		return ((unsigned int)ptr1[i - 1] - (unsigned int)ptr2[i - 1]);
	return ((unsigned int)ptr1[i] - (unsigned int)ptr2[i]);
}
