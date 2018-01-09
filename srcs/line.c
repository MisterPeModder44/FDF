/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:25:24 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/09 17:38:40 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "line.h"


static t_drawdata		*data_construct(t_vec2i *p1, t_vec2i *p2)
{
	t_drawdata *data;

	data = (t_drawdata *)malloc(sizeof(t_drawdata));
	data->delta_x = LN_ABS(*p2->x - *p1->x);
	data->sign_x = *p1->x < *p2->x ? 1 : -1;
	data->delta_y = LN_ABS(*p2->y - *p1->y);
	data->sign_y = *p1->y < *p2->y ? 1 : -1;
	data->delta_error = (data->delta_x > data->delta_y ? data->delta_x :
			-(data->delta_y)) / 2;
	return (data);
}

void				draw_line(t_image *img, t_vec2i *p1, t_vec2i *p2, t_color *color)
{
	int		x;
	int		y;
	int		e2;
	t_drawdata	*data;

	data = data_construct(p1, p2);
	x = *p1->x;
	y = *p1->y;
	while (1)
	{
		img_pixel_put(img, x, y, color);
		if (x == *p2->x && y == *p2->y)
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

void line(t_image *img, int x0, int y0, int x1, int y1, t_color *color) {

	int dx = abs(x1-x0), sx = x0<x1 ? 1 : -1;
	int dy = abs(y1-y0), sy = y0<y1 ? 1 : -1;
	int err = (dx>dy ? dx : -dy)/2, e2;

	for(;;){
		img_pixel_put(img, x0, y0, color);
		if (x0==x1 && y0==y1) break;
		e2 = err;
		if (e2 >-dx) { err -= dy; x0 += sx; }
		if (e2 < dy) { err += dx; y0 += sy; }
	}
}

void				draw_between(t_image *img, t_vec3f *v1, t_vec3f *v2,
		t_color *color)
{
	t_vec2i			*p1;
	t_vec2i			*p2;

	if (!(p1 = new_vec2i(*v1->x, *v1->y)))
		return ;
	if (!(p2 = new_vec2i(*v2->x, *v2->y)))
		return ;
	line(img, *p1->x, *p1->y, *p2->x, *p2->y, color);
	del_vec2((t_vec2 **)&p1);
	del_vec2((t_vec2 **)&p2);
}
