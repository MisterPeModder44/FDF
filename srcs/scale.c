/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 08:26:18 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/10 10:03:34 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_base/list.h>
#include <libft_math/vectors.h>
#include "transform.h"

void			scale(t_vectab *vectab, float x, float y, float z)
{
	uint32_t	ty;
	uint32_t	tx;

	ty = 0;
	while (ty < vectab->height)
	{
		tx = 0;
		while (tx < vectab->width)
		{
			*vectab->tab[ty][tx]->x *= x;
			*vectab->tab[ty][tx]->y *= y;
			*vectab->tab[ty][tx]->z *= z;
			++tx;
		}
		++ty;
	}
}
