/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 09:48:02 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/11 17:10:45 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "fdf.h"
#include "transform.h"

void				project(t_vectab *base, t_vectab **vec, float fov,
		float screen_dist)
{
	uint32_t		ty;
	uint32_t		tx;
	t_vec3f			*tmp;

	if (!*vec)
		*vec = new_vectab(base->width, base->height);
	vectab_copy(base, *vec);
	ty = 0;
	while (ty < (*vec)->height)
	{
		tx = 0;
		while (tx < (*vec)->width)
		{
			tmp = (*vec)->tab[ty][tx];
			if (*tmp->z <= screen_dist)
			{
				*tmp->z = 0;
			}
			else
			{
				*tmp->x *= screen_dist / *tmp->z;
				*tmp->y *= screen_dist / *tmp->z;
				*tmp->z /= cos(fov / 2);
			}
			++tx;
		}
		++ty;
	}
}
