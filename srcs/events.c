/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:58:13 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/16 16:28:16 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "maps.h"
#include "events.h"
#include "transform.h"

int			on_close_window(t_mlx_context *ctx)
{
	del_maps(&(ctx->maps));
	quit_fdf(ctx, NULL);
	return (0);
}

int			on_mouse_pressed(int button, int x, int y, t_mlx_context *ctx)
{
	if (button == SCROLL_UP_KEY || button == SCROLL_DOWN_KEY)
	{
		translate(ctx->curr->base, 0, 0, button == SCROLL_UP_KEY ? -1 : 1);
		project(ctx->curr->base, &ctx->curr->proj, ctx->screen_dist);
		translate(ctx->curr->proj, ctx->width / 2, ctx->height / 2, 0);
		put_fdf_render(ctx, ctx->curr->proj);
	}
	else
	{
		ctx->mouse->pressed = TRUE;
		ctx->mouse->last_x = x;
		ctx->mouse->last_y = y;
		printf("event!\n");
		fflush(stdout);
	}
	return (0);
}

int			on_mouse_released(int button, int x, int y, t_mlx_context *ctx)
{
	if (!(button == SCROLL_UP_KEY && button == SCROLL_DOWN_KEY))
	{
		ctx->mouse->pressed = FALSE;
	}
	x = 0;
	y = 0;
	return (0);
}

int			on_mouse_movement(int x, int y, t_mlx_context *ctx)
{
	if (x < 0 || y < 0)
		ctx->mouse->pressed = FALSE;
	if (ctx->mouse->pressed)
	{
		translate(ctx->curr->base, x - ctx->mouse->last_x,
				y - ctx->mouse->last_y, 0);
		project(ctx->curr->base, &ctx->curr->proj, ctx->screen_dist);
		translate(ctx->curr->proj, ctx->width / 2, ctx->height / 2, 0);
		put_fdf_render(ctx, ctx->curr->proj);
		ctx->mouse->last_x = x;
		ctx->mouse->last_y = y;
	}
	ctx = 0;
	return (0);
}
