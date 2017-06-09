/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aelharim <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2016/12/15 18:57:51 by aelharim          #+#    #+#             */
/*   Updated: 2017/06/09 15:39:04 by aelharim         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
/*
static void		allocation(char **buff, char ***mem)
{
	char *tmp;

	tmp = ft_strjoin(**mem, *buff);
	free(**mem);
	**mem = ft_strdup(tmp);
	free(tmp);
	tmp = NULL;
}

static int		gnl_check(char **mem, char **line)
{
	int		size;
	char	*tmp;

	if (ft_strchr(*mem, '\n') != NULL)
	{
		size = ft_strchr(*mem, '\n') - *mem;
		tmp = ft_strsub(*mem, 0, size);
		*line = ft_strdup(tmp);
		tmp = ft_strdup(*mem);
		free(*mem);
		*mem = ft_strsub(tmp, (size + 1), ft_strlen(tmp));
		free(tmp);
		return (1);
	}
	return (0);
}

static void		gnl_read_check(char **buff, int count, char **line, char ***mem)
{
	int		size;
	char	*tmp;

	size = ft_strchr(*buff, '\n') - *buff;
	tmp = ft_strsub(*buff, 0, size);
	if (**mem)
		*line = ft_strjoin(**mem, tmp);
	else
		*line = ft_strdup(tmp);
	free(**mem);
	**mem = ft_strsub(*buff, (size + 1), count);
	free(tmp);
}

static int		gnl_read(int fd, int count, char **mem, char **line)
{
	char		*buff;

	buff = ft_strnew(BUFF_SIZE);
	while ((count = read(fd, buff, BUFF_SIZE)))
	{
		if (count == -1)
			return (-1);
		buff[count] = '\0';
		if (ft_strchr(buff, '\n') != NULL)
		{
			gnl_read_check(&buff, count, &line[0], &mem);
			break ;
		}
		if (*mem)
			allocation(&buff, &mem);
		else
			*mem = ft_strdup(buff);
	}
	free(buff);
	buff = NULL;
	return (count);
}

int				get_next_line(int fd, char **line)
{
	static char	*mem;
	int			count;

	if (BUFF_SIZE <= 0 || fd < 0 || line == NULL)
		return (-1);
	if (mem)
	{
		if (gnl_check(&mem, &line[0]) == 1)
			return (1);
	}
	if ((count = gnl_read(fd, 0, &mem, &line[0])) == -1)
		return (-1);
	if (count > 0)
		return (1);
	if (mem == NULL)
		return (0);
	*line = ft_strdup(mem);
	free(mem);
	mem = NULL;
	if (line[0][0] == '\0')
		return (0);
	return (1);
}
	*/
static t_ct		*ft_create_list(t_list **lst, const int fd)
{
	t_ct		content;
	t_list		*lst_temp;

	if (fd < 0 || !lst)
		return (NULL);
	lst_temp = *lst;
	while (lst_temp)
	{
		if (((t_ct *)(lst_temp->content))->fd == fd)
			return (lst_temp->content);
		lst_temp = lst_temp->next;
	}
	content.fd = fd;
	if (!(content.r_line = ft_strnew(BUFF_SIZE)))
		return (NULL);
	if (!(lst_temp = ft_lstnew(&content, sizeof(content))))
	{
		free(content.r_line);
		return (NULL);
	}
	ft_lstadd(lst, lst_temp);
	return ((*lst)->content);
}

static int		ft_cut_cpy(char **line, char **r_line)
{
	char		*tmp;
	int			ret;

	ret = 0;
	if ((tmp = ft_strchr(*r_line, '\n')))
	{
		*tmp = '\0';
		if (!(*line = ft_strdup(*r_line)))
			return (-1);
		tmp++;
		ft_strcpy(*r_line, tmp);
		ret = 1;
	}
	else if (ft_strlen(*r_line))
	{
		if (!(*line = ft_strdup(*r_line)))
			return (-1);
		**r_line = '\0';
		ret = 1;
	}
	else if (!(*line = ft_strnew(0)))
		return (-1);
	return (ret);
}

static int		read_buffer(t_ct **content)
{
	char		curr_line[BUFF_SIZE + 1];
	char		*tmp;
	int			ret;

	while (!ft_strchr((*content)->r_line, '\n'))
	{
		ft_bzero(curr_line, BUFF_SIZE + 1);
		if ((ret = read((*content)->fd, curr_line, BUFF_SIZE)) == -1)
			return (-1);
		if (!ret)
			return (0);
		tmp = (*content)->r_line;
		if (!((*content)->r_line = ft_strjoin((*content)->r_line, curr_line)))
			return (-1);
		free(tmp);
	}
	return (1);
}

int				get_next_line(const int fd, char **line)
{
	static t_list	*lst;
	t_ct			*gnl_content;
	int				ret;

	if (BUFF_SIZE <= 0 || !line || !(gnl_content = ft_create_list(&lst, fd)))
		return (-1);
	if ((ret = read_buffer(&gnl_content)) == -1)
		return (-1);
	return (ft_cut_cpy(line, &(gnl_content->r_line)));
}
