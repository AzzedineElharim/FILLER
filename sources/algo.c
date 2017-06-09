/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   algo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/29 16:21:50 by aelharim          #+#    #+#             */
/*   Updated: 2017/06/07 20:01:36 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

int		cut_ft_test(t_fil *env, int i, int j)
{
	env->x = i;
	env->y = j;
	return (0);
}

int		ft_test(t_fil *env, t_piece *p, int j, int i)
{
	int	x;
	int	y;

	x = 0;
	y = 0;
	p->c = 0;
	while ((y < p->h) && (j + y < env->h))
	{
		while ((x < p->l) && (i + x < env->l))
		{
			if ((p->piece[y][x] == '*') && (env->map[j + y][i + x] == env->signe
						|| env->map[j + y][i + x] == env->signe + 32))
				p->c++;
			if ((p->piece[y][x] == '*') && (env->map[j + y][i + x] == env->adv
						|| env->map[j + y][i + x] == env->adv + 32))
				return (1);
			x++;
		}
		x = 0;
		y++;
	}
	if (p->c == 1)
		return (cut_ft_test(env, i, j));
	return (1);
}

void	ft_place(t_fil *env, t_piece *p)
{
	int	i;
	int	j;

	i = -1;
	j = -1;
	while (++j < env->h)
	{
		while (++i < env->l)
		{
			if (env->map[j][i] == env->adv)
				ft_dist(env, p, j, i);
		}
		i = -1;
	}
}

void	ft_algo(t_fil *env, t_piece *piece)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	while (j < env->h - piece->h)
	{
		while (i < env->l - piece->l)
		{
			if ((ft_test(env, piece, j, i) == 0) && (piece->c == 1))
				ft_place(env, piece);
			i++;
		}
		i = 0;
		j++;
	}
	//ft_putstr_fd(ft_itoa(piece->y), 1);
	ft_putnbr_fd(piece->y, 1);
	ft_putchar_fd(' ', 1);
	//ft_putstr_fd(ft_itoa(piece->x), 1);
	ft_putnbr_fd(piece->x, 1);
	ft_putchar_fd('\n', 1);
}
