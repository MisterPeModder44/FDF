/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 10:11:01 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/17 08:58:06 by yguaye           ###   ########.fr       */
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

static void		free_veclst(t_list *list)
{
	t_list	*tmp;

	while (list)
	{
		tmp = list->next;
		free(list);
		list = tmp;
	}
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
	free_veclst(list);
	return (tab);
}
