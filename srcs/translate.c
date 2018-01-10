/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:12:30 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/10 09:37:33 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_math/vectors.h>
#include "fdf.h"

void			translate(t_vectab *vectab, float x, float y, float z)
{
	uint32_t	ty;
	uint32_t	tx;

	ty = 0;
	while (ty < vectab->height)
	{
		tx = 0;
		while (tx < vectab->width)
		{
			*vectab->tab[ty][tx]->x += x;
			*vectab->tab[ty][tx]->y += y;
			*vectab->tab[ty][tx]->z += z;
			++tx;
		}
		++ty;
	}
}
