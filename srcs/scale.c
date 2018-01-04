/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   scale.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/04 08:26:18 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/04 08:28:33 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_base/list.h>
#include <libft_math/vectors.h>

void			scale(t_list *veclst, float x, float y, float z)
{
	t_vec3f		*v;

	while (veclst)
	{
		v = (t_vec3f *)veclst->content;
		*v->x *= x;
		*v->y *= y;
		*v->z *= z;
		veclst = veclst->next;
	}
}
