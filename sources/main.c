/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:00:33 by aelharim          #+#    #+#             */
/*   Updated: 2017/06/09 19:32:40 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	freetab(char **tab, int a)
{
	int	i;
	i = 0;

	while (i < a)
	{
		if (tab[i])
			free(tab[i]);
		i++;
	}
	free(tab);
}

int			main(void)
{
	t_fil	env;
	t_piece	piece;

	ft_initialisation(&env, &piece);
	ft_info(&env);
	while (1)
	{
		re_init(&env, &piece);
		ft_map(&env, &piece);
		ft_algo(&env, &piece);
/*		if (env.map)
			freetab(env.map, env.h);
		if(piece.piece)
			freetab(piece.piece, piece.h);*/
		if (env.cp == 0)
			break ;
	}
	return (0);
}
