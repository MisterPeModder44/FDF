/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_points.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:25:24 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/18 06:16:20 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "fdf.h"


static t_drawdata		*data_construct(t_point *p1, t_point *p2)
{
	t_drawdata *data;

	data = (t_drawdata *)malloc(sizeof(t_drawdata));
	data->delta_x = ABS(p2->x - p1->x);
	data->sign_x = p1->x < p2->x ? 1 : -1;
	data->delta_y = ABS(p2->y - p1->y);
	data->sign_y = p1->y < p2->y ? 1 : -1;
	data->delta_error = (data->delta_x > data->delta_y ? data->delta_x :
			-(data->delta_y)) / 2;
	return (data);
}

void				draw_line(t_mlx_context *ctx, t_point *p1, t_point *p2, int color)
{
	int		x;
	int		y;
	int		e2;
	t_drawdata	*data;

	data = data_construct(p1, p2);
	x = p1->x;
	y = p1->y;
	while (1)
	{
		mlx_pixel_put(ctx->mlx, ctx->win, x, y, color);
		if (x == p2->x && y == p2->y)
			break ;
		if ((e2 = data->delta_error) > -(data->delta_x))
		{
			data->delta_error -= data->delta_y;
			x += data->sign_x;
		}
		if (e2 < data->delta_y)
		{
			data->delta_error += data->delta_x;
			y += data->sign_y;
		}
	}
	free(data);
}

//void				draw_line(t_mlx_context *context, t_point *p1, t_point *p2, int color);

void				draw_line_shadow(t_mlx_context *ctx, t_point *p1,
		t_point *p2, int color)
{
	t_point			s1;
	t_point			s2;

	s1.x = p1->x + 50;
	s1.y = p1->y + 50;
	s2.x = p2->x + 50;
	s2.y = p2->y + 50;
	draw_line(ctx, &s1, &s2, 0);
	draw_line(ctx, p1, p2, color);
}
