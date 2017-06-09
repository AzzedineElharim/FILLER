/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:27:02 by aelharim          #+#    #+#             */
/*   Updated: 2017/06/06 18:17:08 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/filler.h"

void	ft_initialisation(t_fil *env, t_piece *p)
{
	env->j = 0;
	env->l = 0;
	env->h = 0;
	env->cp = 0;
	env->precx = -1;
	env->precy = -1;
	p->h = 0;
	p->l = 0;
	p->x = 0;
	p->y = 0;
	p->c = 0;
}

void	re_init(t_fil *env, t_piece *p)
{
	env->x = 0;
	env->y = 0;
	p->h = 0;
	p->l = 0;
	p->x = 0;
	p->y = 0;
	env->cp = 0;
	p->dist = 0;
}
