/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/07 17:38:08 by aelharim          #+#    #+#             */
/*   Updated: 2017/06/09 14:03:47 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_isspace(int c)
{
	return (c == '\t' || c == '\n' || c == '\v'
			|| c == '\f' || c == '\r' || c == ' ');
}

int		ft_atoi(char *str)
{
	/*int index;
	  int result;
	  int sign;

	  index = 0;
	  result = 0;
	  sign = 1;
	  while ( str[index] && (str[index] == ' ' || str[index] == '\n'
	  || str[index] == '\t' || str[index] == '\v'
	  || str[index] == '\f' || str[index] == '\r'))
	  index++;
	  if (str[index] && str[index] == '-')
	  sign = -1;
	  if (str[index] && (str[index] == '-' || str[index] == '+'))
	  index++;
	  while (str[index] && (str[index] >= '0' && str[index] <= '9'))
	  {
	  result = result * 10 + (str[index] - 48);
	  index++;
	  }
	  return (result * sign);*/
	int	nb;
	int	sign;

	nb = 0;
	sign = 1;
	while (ft_isspace((int)*str))
		str++;
	if (*str == '+' || *str == '-')
	{
		if (*str == '-')
			sign = (-1);
		str++;
	}
	while (ft_isdigit((int)*str))
	{
		nb = nb * 10 + *str - '0';
		str++;
	}
	return (sign * nb);
}
