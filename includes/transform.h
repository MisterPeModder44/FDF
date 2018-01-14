/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:23:14 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/14 12:27:01 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include <libft_math/vectors.h>
# include "fdf.h"

# define FAR_CLIPPING_PLANE 2000.0F

void			translate(t_vectab *vectab, float x, float y, float z);
void			scale(t_vectab *vectab, float x, float y, float z);
void			rotate_x(t_vectab *vectab, float angle);
void			rotate_y(t_vectab *vectab, float angle);
void			rotate_z(t_vectab *vectab, float angle);
void			rotate_mx(t_vectab *vectab, float angle);
void			rotate_my(t_vectab *vectab, float angle);
void			rotate_mz(t_vectab *vectab, float angle);
void			project(t_vectab *base, t_vectab **vec, float screen_dist);

#endif
