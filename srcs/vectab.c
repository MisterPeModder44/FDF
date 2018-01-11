/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vectab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/11 15:14:23 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/11 15:15:42 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"

t_vectab		*new_vectab(uint32_t width, uint32_t height)
{
	t_vectab		*tab;
	uint32_t		y;
	uint32_t		x;

	if (!(tab = (t_vectab*)malloc(sizeof(t_vectab))))
		return (NULL);
	if (!(tab->tab = (t_vec3f ***)malloc(sizeof(t_vec3f **) * height)))
		return (NULL);
	y = 0;
	while (y < height)
	{
		if (!(tab->tab[y] = (t_vec3f **)malloc(sizeof(t_vec3f *) * width)))
			return (NULL);
		x = 0;
		while (x < width)
		{
			tab->tab[y][x] = new_vec3f(0, 0, 0);
			++x;
		}
		++y;
	}
	return (tab);
}

void			vectab_copy(const t_vectab *src, t_vectab *dst)
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
			*dst->tab[y][x]->x = *src->tab[y][x]->x;
			*dst->tab[y][x]->y = *src->tab[y][x]->y;
			*dst->tab[y][x]->z = *src->tab[y][x]->z;
			++x;
		}
		++y;
	}
}

void				delete_vectab(t_vectab **vectab)
{
	uint32_t	ty;
	uint32_t	tx;

	ty = 0;
	while (ty < (*vectab)->height)
	{
		tx = 0;
		while (tx < (*vectab)->width)
		{
			del_vec3((t_vec3 **)&(*vectab)->tab[ty][tx]);
			++tx;
		}
		free((*vectab)->tab[ty]);
		++ty;
	}
	free((*vectab)->tab);
	free(*vectab);
	*vectab = NULL;
}
