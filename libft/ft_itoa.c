/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/22 18:23:39 by aelharim          #+#    #+#             */
/*   Updated: 2016/11/25 16:19:41 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	size_of_str(int n)
{
	size_t		i;

	i = 1;
	while (n /= 10)
		i++;
	return (i);
}

char			*ft_itoa(int n)
{
	char			*str;
	size_t			size_str;
	unsigned int	n_bis;

	size_str = size_of_str(n);
	n_bis = n;
	if (n < 0)
	{
		n_bis = -n;
		size_str++;
	}
	if (!(str = ft_strnew(size_str)))
		return (NULL);
	str[--size_str] = n_bis % 10 + '0';
	while (n_bis /= 10)
		str[--size_str] = n_bis % 10 + '0';
	if (n < 0)
		str[0] = '-';
	return (str);
}
