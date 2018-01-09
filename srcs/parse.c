/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 10:11:01 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/09 18:02:38 by yguaye           ###   ########.fr       */
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

static int		parse_line(const char *line, t_list **lst, const int height)
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

static t_list	*parse_fdf(int fd)
{
	int			ret;
	char		*line;
	t_list		*lst;
	int			ls[2];
	int			l;

	lst = NULL;
	ls[0] = -1;
	l = 0;
	while ((ret = get_next_line(fd, &line)) == 1)
	{
		if ((ls[1] = parse_line(line, &lst, l)) == -1)
			return (exit_parse(&lst, "fdf: parse error"));
		ls[0] = ls[0] == -1 ? ls[1] : ls[0];
		if (ls[0] != ls[1])
			return (exit_parse(&lst, "fdf: cannot have different line sizes!"));
		free(line);
		++l;
	}
	if (ret == -1)
		return (exit_parse(&lst, NULL));
	return (lst);
}

t_list			*read_fdf_file(char *path)
{
	int			fd;
	t_list		*list;

	if ((fd = open(path, O_RDONLY)) == -1)
		return (exit_parse(NULL, NULL));
	if (!(list = parse_fdf(fd)))
		return (NULL);
	if (close(fd) == -1)
		return (exit_parse(&list, NULL));
	return (list);
}
