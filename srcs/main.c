/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:11:27 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/18 08:17:30 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"
#include "libft_base/base.h"

int					on_key_pressed(int keycode, t_mlx_context *ctx)
{
	if (keycode == 53)
	{
		mlx_destroy_window(ctx->mlx, ctx->win);
		delete_matrix(&ctx->mtx);
		exit(0);
	}
	return (0);
}

int					main(int argc, char **argv)
{
	t_mlx_context	ctx;

	if (argc == 2)
	{
		ctx.mlx = mlx_init();
		ctx.width = 1600;
		ctx.height = 900;
		ctx.state = 0;
		ctx.win = mlx_new_window(ctx.mlx, ctx.width,
				ctx.height, "FDF Prototype");
		ctx.mtx = read_matrix(argv[1]);
		draw_matrix(&ctx, ctx.mtx, 0x00FFFFFF);
		mlx_key_hook(ctx.win, (int (*)())&on_key_pressed, &ctx);
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
