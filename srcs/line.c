/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:25:24 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/11 17:14:19 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "line.h"

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
