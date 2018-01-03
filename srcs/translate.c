/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   translate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:12:30 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/03 15:05:30 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_base/list.h>
#include <libft_math/vectors.h>

void			translate(t_list *veclst, float x, float y, float z)
{
	t_vec3f		*vec;

	while (veclst)
	{
		vec = (t_vec3f *)veclst->content;
		*vec->x += x;
		*vec->y += y;
		*vec->z *= z;
		veclst = veclst->next;
	}
}
