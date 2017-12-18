/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   point.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 05:45:08 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/18 05:45:38 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdlib.h>

void				put_point(t_mlx_context *context, t_point *p, int color)
{
	mlx_pixel_put(context->mlx, context->win, p->x, p->y, color);
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

t_point				*set_point(t_point *p, int x, int y)
{
	p->x = x;
	p->y = y;
	return (p);
}

void				del_point(t_point **point)
{
	ft_memdel((void **)point);
}
