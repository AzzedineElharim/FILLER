/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 17:49:30 by aelharim          #+#    #+#             */
/*   Updated: 2016/11/24 17:21:30 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strtrim(char const *s)
{
	int		i;
	int		t;
	char	*str;

	if (!s)
		return (NULL);
	t = ft_strlen(s);
	i = 0;
	while (s[t - 1] == ' ' || s[t - 1] == '\t' || s[t - 1] == '\n')
		t--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		t--;
		i++;
	}
	if (t < 0)
		t = 0;
	if (!(str = (char*)malloc(sizeof(char) * (t + 1))))
		return (NULL);
	s = s + i;
	i = -1;
	while (++i < t)
		str[i] = *s++;
	str[i] = '\0';
	return (str);
}
