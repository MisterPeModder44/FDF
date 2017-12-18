/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:19:45 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/18 07:46:09 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <mlx.h>
# include "libft_base/base.h"
# include "matrix.h"

# define ABS(x) (x < 0 ? -x : x)
# define DIFF(x, y) (x < y ? 1 : -1)

typedef struct		s_mlx_context
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	t_matrix		*mtx;
	int				state;
}					t_mlx_context;

typedef struct		s_point
{
	int				x;
	int				y;
}					t_point;

typedef struct		s_drawdata
{
	int				delta_x;
	int				sign_x;
	int				delta_y;
	int				sign_y;
	int				delta_error;
}					t_drawdata;

void				draw_line(t_mlx_context *context, t_point *p1, t_point *p2,
		int color);
void				draw_line_shadow(t_mlx_context *context, t_point *p1,
		t_point *p2, int color);
void				put_point(t_mlx_context *context, t_point *p, int color);
t_point				*make_point(int x, int y);
t_point				*set_point(t_point *p, int x, int y);
void				del_point(t_point **point);
void				draw_matrix(t_mlx_context *ctx, t_matrix *mtx, int color);
void				put_square(t_mlx_context *context, t_point *s, t_point *e,
		int color);

int					return_error(char *s, int r);
void				exit_error(char *s);

#endif
