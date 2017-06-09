/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tools.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/30 14:46:26 by aelharim          #+#    #+#             */
/*   Updated: 2017/06/06 18:17:38 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_moy(t_piece *p)
{
	int	x;
	int	y;
	int	c;

	x = -1;
	y = -1;
	p->moyx = 0;
	p->moyy = 0;
	c = 0;
	while (++y < p->h)
	{
		while (++x < p->l)
		{
			if (p->piece[y][x] == '*')
			{
				p->moyx += x;
				p->moyy += y;
				c++;
			}
		}
		x = -1;
	}
	p->moyx = p->moyx / c;
	p->moyy = p->moyy / c;
}

void	ft_dist(t_fil *env, t_piece *p, int advy, int advx)
{
	int	mex;
	int	mey;
	int	dist;

	ft_moy(p);
	mex = env->x + p->moyx;
	mey = env->y + p->moyy;
	dist = ft_abs(advx - mex) + ft_abs(advy - mey);
	if (env->cp == 0)
	{
		p->dist = dist;
		p->x = env->x;
		p->y = env->y;
	}
	else
	{
		if (dist < p->dist)
		{
			p->dist = dist;
			p->x = env->x;
			p->y = env->y;
		}
	}
	env->cp = 1;
}
