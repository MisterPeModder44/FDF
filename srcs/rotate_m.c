/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate_m.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 11:22:45 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/13 11:47:23 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <libft_base/list.h>
#include <libft_math/vectors.h>
#include "transform.h"

void			rotate_mx(t_vectab *vectab, float angle)
{
	translate(vectab, -vectab->width / 2, -vectab->height / 2, 0);
	rotate_x(vectab, angle);
	translate(vectab, vectab->width / 2, vectab->height / 2, 0);
}

void			rotate_my(t_vectab *vectab, float angle)
{
	translate(vectab, -vectab->width / 2, -vectab->height / 2, 0);
	rotate_y(vectab, angle);
	translate(vectab, vectab->width / 2, vectab->height / 2, 0);
}

void			rotate_mz(t_vectab *vectab, float angle)
{
	translate(vectab, -vectab->width / 2, -vectab->height / 2, 0);
	rotate_z(vectab, angle);
	translate(vectab, vectab->width / 2, vectab->height / 2, 0);
}
