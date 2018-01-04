/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   transform.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/03 14:23:14 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/04 08:26:14 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TRANSFORM_H
# define TRANSFORM_H

# include <libft_base/list.h>

void			translate(t_list *veclst, float x, float y, float z);
void			scale(t_list *veclst, float x, float y, float z);
void			rotate_x(t_list *veclst, float angle);
void			rotate_y(t_list *veclst, float angle);
void			rotate_z(t_list *veclst, float angle);

#endif
