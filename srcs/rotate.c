/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 15:31:05 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/03 17:15:45 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <libft_base/list.h>
#include <libft_math/vectors.h>
#include <stdio.h>

void			rotate_x(t_list *veclst, double angle)
{
	t_vec3f		*v;
	double		cos_v;
	double		sin_v;
	float		tmp;

	while (veclst)
	{
		v = (t_vec3f *)veclst->content;
		cos_v = cos(angle);
		sin_v = sin(angle);
		tmp = *v->y;
		*v->y = (float)(cos_v * *v->y + -sin_v * *v->z);
		*v->z = (float)(sin_v * tmp + cos_v * *v->z);
		veclst = veclst->next;
	}
}

void			rotate_y(t_list *veclst, double angle)
{
	t_vec3f		*v;
	double		cos_v;
	double		sin_v;
	float		tmp;

	while (veclst)
	{
		v = (t_vec3f *)veclst->content;
		cos_v = cos(angle);
		sin_v = sin(angle);
		tmp = *v->x;
		*v->x = (float)(cos_v * *v->x + sin_v * *v->z);
		*v->z = (float)(-sin_v * tmp + cos_v * *v->z);
		veclst = veclst->next;
	}
}

void			rotate_z(t_list *veclst, double angle)
{
	t_vec3f		*v;
	double		cos_v;
	double		sin_v;
	float		tmp;

	while (veclst)
	{
		v = (t_vec3f *)veclst->content;
		cos_v = cos(angle);
		sin_v = sin(angle);
		tmp = *v->x;
		*v->x = (float)(cos_v * *v->x + -sin_v * *v->y);
		*v->y = (float)(sin_v * tmp + cos_v * *v->y);
		veclst = veclst->next;
	}
}
