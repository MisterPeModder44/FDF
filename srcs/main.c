/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:21:03 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/02 18:36:39 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"
#include "libft_base/base.h"

void		quit_fdf(t_mlx_context *ctx, const char *reason)
{
	mlx_destroy_window(ctx->mlx, ctx->win);
	if (reason)
		ft_putendl_fd(reason, 2);
	if (ctx->img)
		mlx_destroy_image(ctx->mlx, ctx->img);
	exit(reason != NULL);
}

static void	on_key_released(int key, t_mlx_context *ctx)
{
	if (key == 53)
		quit_fdf(ctx, NULL);
	else
	{
		ft_putstr("key: ");
		ft_putnbr(key);
		ft_putendl("");
	}
}

int			main(void)
{
	t_mlx_context	ctx;

	ctx.mlx = mlx_init();
	ctx.width = 800;
	ctx.height = 450;
	ctx.win = mlx_new_window(ctx.mlx, ctx.width, ctx.height, "- Fil De Fer -");
	ctx.img = NULL;
	mlx_key_hook(ctx.win, (int (*)())&on_key_released, &ctx);
	put_fdf_render(&ctx);
	mlx_loop(ctx.mlx);
	return (0);
}
