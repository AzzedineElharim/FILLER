/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/28 18:07:36 by aelharim          #+#    #+#             */
/*   Updated: 2016/11/28 18:08:06 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_sqrt(int nb)
{
	int	index;

	index = 0;
	while (index <= nb)
	{
		if (index * index == nb)
			return (index);
		else
			index++;
	}
	return (0);
}
