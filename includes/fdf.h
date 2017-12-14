/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:19:45 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/14 18:32:54 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft_base/base.h"

# define ABS(x) (x < 0 ? -x : x)
# define DIFF(x, y) (x < y ? 1 : -1)

typedef struct		s_mlx_context
{
	void			*mlx;
	void			*win;
}					t_mlx_context;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_point_grid
{
	int				width;
	int				height;
	t_point			**grid;
}					t_point_grid;

void				draw_line(t_mlx_context *context, t_point *p1, t_point *p2);
t_point				*make_point(int x, int y);
void				del_point(t_point **point);

#endif
