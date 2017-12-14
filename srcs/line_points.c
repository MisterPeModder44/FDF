/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:25:24 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/14 18:28:44 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"

void				draw_line(t_mlx_context *context, t_point *p1, t_point *p2)
{
	int			dx;
	int			dy;
	int			e;

	e = p2->x - p1->x;
	dx = e * 2;
	dy = (p2->y - p1->y) * 2;
	while (p1->x <= p2->x)
	{
		mlx_pixel_put(context->mlx, context->win, p1->x, p1->y, 0x00FFFFFF);
		++p1->x;
		if ((e -= dy) <= 0)
		{
			++p1->y;
			e += dx;
		}
	}
}


t_point				*make_point(int x, int y)
{
	t_point			*point;
	if (!(point = (t_point *)malloc(sizeof(t_point))))
		return (NULL);
	point->x = x;
	point->y = y;
	return (point);
}

void				del_point(t_point **point)
{
	ft_memdel((void **)point);
}
