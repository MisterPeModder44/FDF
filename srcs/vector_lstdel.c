/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vector_lstdel.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 10:25:19 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/10 10:10:47 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_base/list.h>
#include <libft_math/vectors.h>
#include "fdf.h"

static void		delete_vector_node(void *vec, size_t vecsize)
{
	if (vecsize == sizeof(t_vec2))
		del_vec2((t_vec2 **)&vec);
	else if (vecsize == sizeof(t_vec3))
		del_vec3((t_vec3 **)&vec);
	else
		del_vec4((t_vec4 **)&vec);
}

void			delete_vector_list(t_list **list)
{
	ft_lstdel(list, &delete_vector_node);
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
