/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 10:11:01 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/16 17:53:48 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>
#include <get_next_line.h>
#include <libft_base/io.h>
#include <libft_base/list.h>
#include <libft_math/vectors.h>
#include <libft_base/stringft.h>
#include "fdf.h"

static void		*exit_parse(t_list **lst, const char *line)
{
	if (line)
		ft_putendl_fd(line, 2);
	else
		perror("fdf");
	if (lst && *lst)
		delete_vector_list(lst);
	return (NULL);
}

static int		parse_line(const char *line, t_list **lst, int height)
{
	char		**tab;
	int			i;
	t_vec3f		*vec;
	t_list		*nlst;

	if (!(tab = ft_strsplit(line, ' ')))
		return (-1);
	i = 0;
	while (tab[i])
	{
		if (!(vec = new_vec3f(i, ft_atoi(tab[i]), height)))
			return (-1);
		if (!(nlst = ft_lstnew(vec, sizeof(t_vec3))))
			return (-1);
		free(vec);
		ft_lstadd(lst, nlst);
		++i;
	}
	ft_strtabdel(&tab);
	return (i);
}

static t_list	*parse_fdf(int fd, int *line_size, int *lines)
{
	int			ret;
	char		*line;
	t_list		*lst;
	int			ls;

	lst = NULL;
	*line_size = -1;
	*lines = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if ((ls = parse_line(line, &lst, *lines)) == -1)
			return (exit_parse(&lst, "fdf: parse error"));
		*line_size = *line_size == -1 ? ls : *line_size;
		if (*line_size != ls)
			return (exit_parse(&lst, "fdf: cannot have different line sizes!"));
		free(line);
		++*lines;
	}
	if (ret == -1)
		return (exit_parse(&lst, NULL));
	return (lst);
}

static t_vectab	*convert_to_tab(t_list *list, int line_size, int lines)
{
	t_vectab	*tab;
	int			i;
	int			j;

	if (!(tab = (t_vectab *)malloc(sizeof(t_vectab))))
		return (NULL);
	tab->width = line_size;
	tab->height = lines;
	if (!(tab->tab = (t_vec3f ***)malloc(sizeof(t_vec3f **) * lines)))
		return (NULL);
	i = -1;
	while (++i < lines)
	{
		if (!(tab->tab[i] = (t_vec3f **)malloc(sizeof(t_vec3f *) *
						line_size)))
			return (NULL);
		j = -1;
		while (list && ++j < line_size)
		{
			tab->tab[i][j] = list->content;
			list = list->next;
		}
	}
	return (tab);
}

t_vectab		*read_fdf_file(char *path)
{
	int			fd;
	t_list		*list;
	int			line_size;
	int			lines;
	t_vectab	*tab;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (exit_parse(NULL, NULL));
	if (!(list = parse_fdf(fd, &line_size, &lines)))
		return (NULL);
	if (!(tab = convert_to_tab(list, line_size, lines)) || close(fd) == -1)
		return (exit_parse(&list, NULL));
	while (list)
	{
		free(list);
		list = list->next;
	}
	return (tab);
}
