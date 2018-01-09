/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   project.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 09:48:02 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/09 16:01:00 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include "transform.h"


void				project(t_list *veclst, float fov, float screen_dist)
{
	t_vec3f			*tmp;
	float			offset;
	float			coef;

	offset = screen_dist / tan(fov);
	while (veclst->next)
	{
		tmp = (t_vec3f *)veclst->content;
		coef = (*tmp->z / sin(fov)) / screen_dist;
		*tmp->z = ((float)sqrt(*tmp->x * *tmp->x + *tmp->z * *tmp->z)) / coef;
		*tmp->x = *tmp->x / coef + offset;
		*tmp->y = *tmp->y / coef + offset;
		veclst = veclst->next;
	}
}
