/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:19:45 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/18 15:39:13 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

typedef struct		s_mlx_context
{
	void			*mlx;
	void			*win;
	int				width;
	int				height;
	void			*img;
}					t_mlx_context;

void				quit_fdf(t_mlx_context *ctx, char *reason);
void				put_fdf_render(t_mlx_context *ctx);

#endif
