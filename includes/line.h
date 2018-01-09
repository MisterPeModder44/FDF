/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/09 17:06:21 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/09 17:35:12 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LINE_H
# define LINE_H

# include <libft_math/vectors.h>
# include "fdf.h"
# include "image.h"

# define LN_ABS(x) (x < 0 ? -x : x)

typedef struct		s_drawdata
{
	int				delta_x;
	int				delta_y;
	int				sign_x;
	int				sign_y;
	float			delta_error;
}					t_drawdata;

void				draw_between(t_image *img, t_vec3f *v1, t_vec3f *v2,
		t_color *color);
void				draw_line(t_image *img, t_vec2i *p1, t_vec2i *p2,
		t_color *color);

#endif
