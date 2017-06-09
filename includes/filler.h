/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   filler.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/05/24 14:00:51 by aelharim          #+#    #+#             */
/*   Updated: 2017/05/31 15:53:23 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLER_H
# define FILLER_H
# include "../libft/libft.h"
# include <unistd.h>
# include <stdlib.h>
# include <stdio.h> // a sup
typedef struct		s_fil
{
	int				j; //joueur
	int				l; //largeur
	int				h;//hauteur
	char			**map;//map
	char			signe;
	char			adv;
	int				x;//coordonne pt en haut a gauche de la piece
	int				y;
	int				cp;
	int				precx;
	int				precy;
}					t_fil;

typedef	struct		s_piece
{
		int			h;
		int			l;
		char		**piece;
		int			x;
		int			y;
		int			c;
		int			moyy;
		int			moyx;
		int			dist;
}					t_piece;

void				ft_initialisation(t_fil *env, t_piece *piece);
void				ft_info(t_fil *env);
void				ft_map(t_fil *env, t_piece *piece);
void				ft_moy(t_piece *p);
void				ft_dist(t_fil *env, t_piece *piece, int j, int i);
void				ft_algo(t_fil *env, t_piece *piece);
void				re_init(t_fil *env, t_piece *p);
#endif
