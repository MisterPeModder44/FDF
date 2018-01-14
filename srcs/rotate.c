/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:31:05 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/14 12:26:39 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <libft_base/list.h>
#include <libft_math/vectors.h>
#include "transform.h"

void			rotate_x(t_vectab *vec, float angle)
{
	double		cos_v;
	double		sin_v;
	float		tmp;
	uint32_t	ty;
	uint32_t	tx;

	ty = 0;
	while (ty < vec->height)
	{
		tx = 0;
		while (tx < vec->width)
		{
			cos_v = cos(angle);
			sin_v = sin(angle);
			tmp = *vec->tab[ty][tx]->y;
			*vec->tab[ty][tx]->y = (float)(cos_v * *vec->tab[ty][tx]->y +
					-sin_v * *vec->tab[ty][tx]->z);
			*vec->tab[ty][tx]->z = (float)(sin_v * tmp + cos_v *
					*vec->tab[ty][tx]->z);
			++tx;
		}
		++ty;
	}
}

void			rotate_y(t_vectab *vec, float angle)
{
	double		cos_v;
	double		sin_v;
	float		tmp;
	uint32_t	ty;
	uint32_t	tx;

	ty = 0;
	while (ty < vec->height)
	{
		tx = 0;
		while (tx < vec->width)
		{
			cos_v = cos(angle);
			sin_v = sin(angle);
			tmp = *vec->tab[ty][tx]->y;
			*vec->tab[ty][tx]->x = (float)(cos_v * *vec->tab[ty][tx]->x +
					sin_v * *vec->tab[ty][tx]->z);
			*vec->tab[ty][tx]->z = (float)(-sin_v * tmp + cos_v *
					*vec->tab[ty][tx]->z);
			++tx;
		}
		++ty;
	}
}

void			rotate_z(t_vectab *vec, float angle)
{
	double		cos_v;
	double		sin_v;
	float		tmp;
	uint32_t	ty;
	uint32_t	tx;

	ty = 0;
	while (ty < vec->height)
	{
		tx = 0;
		while (tx < vec->width)
		{
			cos_v = cos(angle);
			sin_v = sin(angle);
			tmp = *vec->tab[ty][tx]->y;
			*vec->tab[ty][tx]->x = (float)(cos_v * *vec->tab[ty][tx]->x +
					-sin_v * *vec->tab[ty][tx]->y);
			*vec->tab[ty][tx]->y = (float)(sin_v * tmp + cos_v *
					*vec->tab[ty][tx]->y);
			++tx;
		}
		++ty;
	}
}
