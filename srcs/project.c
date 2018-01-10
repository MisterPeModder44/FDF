/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 09:48:02 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/10 15:53:44 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <stdio.h>
#include "transform.h"

static t_vectab		*new_vectab(uint32_t width, uint32_t height)
{
	t_vectab		*tab;
	uint32_t		y;

	if (!(tab = (t_vectab*)malloc(sizeof(t_vectab))))
		return (NULL);
	if (!(tab->tab = (t_vec3f ***)malloc(sizeof(t_vec3f **) * height)))
		return (NULL);
	y = 0;
	while (y < height)
	{
		if (!(tab->tab[y] = (t_vec3f **)malloc(sizeof(t_vec3f *) * width)))
			return (NULL);
		++y;
	}
	return (tab);
}

static void			vectab_copy(const t_vectab *src, t_vectab *dst)
{
	uint32_t		y;
	uint32_t		x;

	y = 0;
	dst->width = src->width;
	dst->height = src->height;
	while (y < src->height)
	{
		x = 0;
		while (x < src->width)
		{
			dst->tab[y][x] = new_vec3f(*src->tab[y][x]->x,
					*src->tab[y][x]->y, *src->tab[y][x]->z);
			++x;
		}
		++y;
	}
}

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
			*tmp->x *= screen_dist / *tmp->z;
			*tmp->y *= screen_dist / *tmp->z;
			*tmp->z /= cos(fov / 2);
			++tx;
		}
		++ty;
	}
}
