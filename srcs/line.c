/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 17:25:24 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/14 11:58:49 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "line.h"

static void			line(t_image *img, t_vec2i *p0, t_vec2i *p1, t_color *color)
{
	int				d[2];
	int				s[2];
	int				err;
	int				e2;

	d[0] = abs(*p1->x - *p0->x);
	s[0] = *p0->x < *p1->x ? 1 : -1;
	d[1] = abs(*p1->y - *p0->y);
	s[1] = *p0->y < *p1->y ? 1 : -1;
	err = (d[0] > d[1] ? d[0] : -d[1]) / 2;
	while (1)
	{
		img_pixel_put(img, *p0->x, *p0->y, color);
		if (*p0->x == *p1->x && *p0->y == *p1->y)
			break ;
		e2 = err;
		err -= e2 > -d[0] ? d[1] : 0;
		err += e2 < d[1] ? d[0] : 0;
		*p0->x += e2 > -d[0] ? s[0] : 0;
		*p0->y += e2 < d[1] ? s[1] : 0;
	}
}

void				draw_between(t_image *img, t_vec3f *v1, t_vec3f *v2,
		t_color *color)
{
	t_vec2i			*p0;
	t_vec2i			*p1;

	if (!(p0 = new_vec2i(*v1->x, *v1->y)))
		return ;
	if (!(p1 = new_vec2i(*v2->x, *v2->y)))
		return ;
	line(img, p0, p1, color);
	del_vec2((t_vec2 **)&p0);
	del_vec2((t_vec2 **)&p1);
}
