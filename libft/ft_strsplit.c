/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   strsplit.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/11/21 18:15:09 by aelharim          #+#    #+#             */
/*   Updated: 2017/06/09 14:09:20 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*

   static int	ft_count_word(char *s, char c)
   {
   size_t	word;
   size_t	i;

   i = 0;
   word = 0;
   if (s[i] && (s[i] != c) && (s[i + 1] != c) && (s[i + 1] != 0))
   word++;
   while (s[i])
   {
   if ((s[i] == c) && (s[i + 1] != c) && (s[i + 1] != 0))
   word++;
   i++;
   }
   return (word);
   }

   static int	ft_splitstr(char **tab, char *s, char c, size_t len)
   {
   size_t	count;
   size_t	wordlen;
   size_t	i;

   count = 0;
   i = 0;
   while (count < len)
   {
   wordlen = 0;
   while (s[i] == c && s[i])
   i++;
   while (s[i] != c && s[i])
   wordlen++, i++;
   if ((tab[count] = ft_strsub(&s[i - wordlen], 0, wordlen)) == NULL)
   return (0);
   count++;
   }
   tab[count] = 0;
   return (1);
   }

   char		**ft_strsplit(char const *s, char c)
   {
   char	**ret;
   int		len;

   if (s)
   {
   len = ft_count_word((char*)s, c);
   if ((ret = (char**)ft_memalloc(sizeof(char*) * len + 1)) == NULL)
   return (NULL);
   if (ft_splitstr(ret, (char*)s, c, len))
   return (ret);
   else
   {
   free(ret);
   ret = NULL;
   }
   return (ret);
   }
   return (NULL);
   }
   */

static char		*del_spaces(const char *s, char c)
{
	while (*s == c)
		s++;
	return ((char*)s);
}

static int		nb_w(const char *str, char c)
{
	int i;
	int nb;

	i = 0;
	nb = 0;
	while (str && *(str + i))
	{
		while (*(str + i) && *(str + i) == c)
			i++;
		if (*(str + i))
			nb++;
		while (*(str + i) && *(str + i) != c)
			i++;
	}
	return (nb);
}

static int		ft_strlen_c(const char *s, char c)
{
	int		nb;
	int		i;

	nb = 0;
	i = 0;
	while (s[i] != c && s[i] != '\0')
	{
		i++;
		nb++;
	}
	return (nb);
}

static void		zbeub(int *i, int *mots, const char *s, char c)
{
	*i = -1;
	*mots = nb_w(s, c);
}

char			**ft_strsplit(const char *s, char c)
{
	int		i;
	int		j;
	char	**t;
	int		mots;
	int		taille;

	if (!s)
		return (NULL);
	s = del_spaces(s, c);
	if (!(t = (char**)malloc(sizeof(char*) * (nb_w(s, c) + 1))))
		return (NULL);
	zbeub(&i, &mots, s, c);
	while (++i < mots)
	{
		s = del_spaces(s, c);
		taille = ft_strlen_c(s, c);
		if (!(t[i] = (char*)malloc(sizeof(char) * (taille + 1))))
			return (NULL);
		j = -1;
		while (++j < taille)
			t[i][j] = *s++;
		t[i][j] = '\0';
	}
	t[i] = NULL;
	return (t);
}
