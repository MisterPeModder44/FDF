/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   draw.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 04:45:14 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/18 07:46:27 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include <stdio.h>

void				draw_matrix(t_mlx_context *ctx, t_matrix *mtx, int color)
{
	if (ctx && mtx)
	{
		color = 0;
	}
}

void				put_square(t_mlx_context *context, t_point *s, t_point *e,
		int color)
{
	int				ox;
	int				oy;

	oy = s->y;
	ox = s->x;
	while (s->y <= e->y)
	{
		s->x = ox;
		while (s->x <= e->x)
		{
			put_point(context, s, color);
			++s->x;
		}
		++s->y;
	}
	s->y = oy;
}

