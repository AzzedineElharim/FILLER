/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   info.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 15:01:16 by aelharim          #+#    #+#             */
/*   Updated: 2017/06/09 17:22:26 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "../includes/filler.h"

void		ft_info(t_fil *env)
{
	char	*stock;

	stock = "\0";
	get_next_line(0, &stock);
	if (stock[0] == '$')
	{
		env->j = ft_atoi(&stock[10]);
		if (env->j == 1)
			env->signe = 'O';
		else
			env->signe = 'X';
		if (env->signe == 'O')
			env->adv = 'X';
		else
			env->adv = 'O';
	}
	free(stock);
	get_next_line(0, &stock);
	if (stock[0] == 'P')
	{	env->h = ft_atoi(&stock[8]);
		env->l = ft_atoi(&stock[11]);
	}
	free(stock);
}

void		ft_piece(t_piece *piece)
{
	char	*stock;
	char	*tmp;
	char	*str;
	int		nb;
	int		i;

	i = 0;
	str = NULL;
	nb = 0;
	tmp = "\0";
	stock = "\0";
	get_next_line(0, &stock);
	if (stock[0] == 'P')
	{
		while (ft_isdigit(stock[i]) == 0)
			i++;
		piece->h = ft_atoi(&stock[i]);
		while (ft_isdigit(stock[i]) == 1)
			i++;
		i++;
		piece->l = ft_atoi(&stock[i]);
	}
	free(stock);
	while (get_next_line(0, &stock) > 0)
	{
		if (str)
			tmp = ft_strjoin(str, stock);
		else
			tmp = ft_strjoin("\0", stock);
		free(stock);
		str = ft_strjoin(tmp, "\n");
		free(tmp);
		nb++;
		if (nb == piece->h)
			break ;
	}
	piece->piece = ft_strsplit(str, '\n');
	free(str);
}

void		ft_map(t_fil *env, t_piece *piece)
{
	char	*stock;
	char	*tmp;
	char	*str;
	int		nb;

	nb = 0;
	str = NULL;
	tmp = "\0";
	while (get_next_line(0, &stock) > 0)
	{
		if (ft_isdigit(stock[0]) == 1)
		{
			if (str)
				tmp = ft_strjoin(str, &stock[4]);
			else
				tmp = ft_strjoin("\0", &stock[4]);
			str = ft_strjoin(tmp, "\n");
			free(tmp);
			nb++;
		}
		free(stock);
		if (env->h == nb)
			break ;
	}
	env->map = ft_strsplit(str, '\n');
	free(str);
	ft_piece(piece);
}
