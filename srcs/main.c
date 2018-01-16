/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:21:03 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/16 17:53:33 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include <libft_base/base.h>
#include <libft_math/vectors.h>
#include "fdf.h"
#include "maps.h"
#include "transform.h"
#include "events.h"
#include "utils.h"

void			quit_fdf(t_mlx_context *ctx, const char *reason)
{
	if (ctx)
		mlx_destroy_window(ctx->mlx, ctx->win);
	if (reason)
		ft_putendl_fd(reason, 2);
	if (ctx && ctx->img)
		mlx_destroy_image(ctx->mlx, ctx->img);
	exit(reason != NULL);
}

static void		init_window(t_mlx_context *ctx)
{
	ctx->screen_dist = 10.0f;
	ctx->mlx = mlx_init();
	ctx->width = 800;
	ctx->height = 800;
	ctx->win = mlx_new_window(ctx->mlx, ctx->width, ctx->height,
			"- Fil De Fer -");
	ctx->img = NULL;
	ctx->draw_diags = 0;
	ctx->mouse->last_x = 0;
	ctx->mouse->last_y = 0;
	ctx->mouse->pressed = FALSE;
	mlx_key_hook(ctx->win, (int (*)())&on_key_released, ctx);
	mlx_mouse_hook(ctx->win, (int (*)())&on_mouse_pressed, ctx);
	mlx_hook(ctx->win, X11_DESTROYNOTIFY, X11_STRUCTURENOTIFYMASK,
			(int (*)())&on_close_window, ctx);
	mlx_hook(ctx->win, X11_MOTIONNOTIFY, 0,
			(int (*)())&on_mouse_movement, ctx);
	mlx_hook(ctx->win, X11_BUTTONRELEASE, 0,
			(int (*)())&on_mouse_released, ctx);
}

int				main(int ac, char **av)
{
	t_mlx_context	ctx;
	t_mouse			mouse;
	int				arg;

	if (ac < 2)
		quit_fdf(NULL, "fdf: too few arguments!");
	arg = 0;
	while (++arg < ac)
	{
		if (add_map_file(&ctx.maps, av[arg]) == FALSE)
			quit_fdf(NULL, "fdf: could not read file!");
	}
	ctx.mouse = &mouse;
	init_window(&ctx);
	ctx.curr = ctx.maps->prev;
	project(ctx.curr->base, &ctx.curr->proj, ctx.screen_dist);
	translate(ctx.curr->proj, ctx.width / 2, ctx.height / 2, 0);
	put_fdf_render(&ctx, ctx.curr->proj);
	mlx_loop(ctx.mlx);
	return (0);
}
