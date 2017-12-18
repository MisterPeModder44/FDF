/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:11:27 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/18 04:27:54 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"
#include "matrix.h"
#include "libft_base/base.h"

void				on_key_pressed(int keycode, void *param)
{
	t_mlx_context	*context;

	context = (t_mlx_context *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(context->mlx, context->win);
		exit(0);
	}
}

void				on_mouse_clicked(int button, int x, int y, void *param)
{
	t_mlx_context	*context;

	context = (t_mlx_context *)param;
	if (button == 1 && x >= 1575 && y <= 25)
	{
		mlx_destroy_window(context->mlx, context->win);
		exit(0);
	}
}

void				put_square(t_mlx_context *context, t_point *s, t_point *e,
		int color)
{
	int				ox;
	int				oy;

	oy = s->y;
	ox = s->x;
	while (s->y <= e->y)
	{
		s->x = ox;
		while (s->x <= e->x)
		{
			put_point(context, s, color);
			++s->x;
		}
		++s->y;
	}
	s->y = oy;
}

int					main(int argc, char **argv)
{
	t_mlx_context	ctx;
	t_point			p1;
	t_point			p2;
	t_matrix		*matrix;

	if (argc == 2)
	{
		ctx.mlx = mlx_init();
		ctx.win = mlx_new_window(ctx.mlx, 1600,
				900, "FDF Prototype");
		matrix = read_matrix(argv[1]);
		delete_matrix(&matrix);
		draw_line(&ctx, set_point(&p1, 100, 100), set_point(&p2, 1500, 800));
		put_square(&ctx, set_point(&p1, 0, 0), set_point(&p2, 1600, 25), 0x00FFFFFF);
		put_square(&ctx, set_point(&p1, 1575, 0), set_point(&p2, 1600, 25), 0x00aa0000);
		mlx_string_put(ctx.mlx, ctx.win, 5, 0, 0, "FDF - prototype mode");
		mlx_key_hook(ctx.win, (int (*)())&on_key_pressed, &ctx);
		mlx_mouse_hook(ctx.win, (int (*)())&on_mouse_clicked, &ctx);
		mlx_loop(ctx.mlx);
	}
	else
	{
		ft_putstr_fd("usage: ", 2);
		ft_putstr_fd(argv[0], 2);
		ft_putendl_fd(" <source>", 2);
		return (-2);
	}
	return (0);
}
