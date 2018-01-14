/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:06:21 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/14 11:43:00 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include <libft_math/vectors.h>
# include "fdf.h"
# include "image.h"

void				draw_between(t_image *img, t_vec3f *v1, t_vec3f *v2,
		t_color *color);

#endif
