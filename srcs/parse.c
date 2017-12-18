/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 03:42:34 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/18 04:50:01 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "matrix.h"
#include "fdf.h"
#include "libft_base/base.h"

static int			pml_2(char **vert_data, int *verts)
{
	int				x;

	x = -1;
	while (vert_data[++x])
	{
		if (!ft_strisnumber(vert_data[x]))
			return (return_error("fdf: invalid vertex height", 1));
		verts[x] = ft_atoi(vert_data[x]);
	}
	return (0);
}

int			parse_matrix_line(char *line, t_matrix *m)
{
	char			**vert_data;
	int				tlen;
	int				ret;
	t_list			*vert;

	if (!(vert_data = ft_strsplit(line, ' ')) || !*vert_data)
		return (return_error("fdf: couldn't split line", -2));
	tlen = (int)ft_strtablen(vert_data);
	if (m->width == -1)
		m->width = tlen;
	else if (m->width != tlen)
	{
		ft_strtabdel(&vert_data);
		return (return_error("fdf: irregular line sizes", -2));
	}
	if (!(vert = ft_lstnew(&ret, sizeof(int) * tlen)))
		ret = 1;
	else
	{
		ret = pml_2(vert_data, (int *)vert->content);
		ft_lstadd(&m->verts, vert);
	}
	ft_strtabdel(&vert_data);
	return (ret == 1 ? -2 : 0);
}
