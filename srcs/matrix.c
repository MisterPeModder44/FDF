/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 00:25:20 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/18 03:54:03 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
#include "matrix.h"
#include "fdf.h"
#include "libft_base/base.h"
#include "get_next_line.h"

static void			read_matrix_lines(int fd, t_matrix *matrix)
{
	char			*line;
	int				ret;

	matrix->width = -1;
	matrix->height = 0;
	matrix->verts = NULL;
	while ((ret = get_next_line(fd, &line)) > 0)
	{
		ret = parse_matrix_line(line, matrix);
		++matrix->height;
		ft_strdel(&line);
		if (ret < 0)
			break;
	}
	if (ret < 0)
	{
		delete_matrix(&matrix);
		if (ret == -1)
			exit_error("fdf: get_next_line error");
		else
			exit(-1);
	}
}

t_matrix			*read_matrix(char *file)
{
	t_matrix		*matrix;
	int				fd;

	if (!(matrix = (t_matrix *)malloc(sizeof(t_matrix))))
		exit_error("fdf: couldn't allocate matrix");
	if ((fd = open(file, O_RDONLY)) == -1)
	{
		free(matrix);
		exit_error("fdf: couldn't open file");
	}
	read_matrix_lines(fd, matrix);
	if (close(fd) == -1)
	{
		delete_matrix(&matrix);
		exit_error("fdf: couldn't close file");
	}
	return (matrix);
}

static void			del_mlist(void *addr, size_t size)
{
	size = 0;
	free(addr);
}

void				delete_matrix(t_matrix **matrix)
{
	ft_lstdel(&(*matrix)->verts, &del_mlist);
	free((*matrix)->verts);
	ft_memdel((void **)matrix);
}
