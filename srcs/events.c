/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 13:58:13 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/16 15:10:11 by yguaye           ###   ########.fr       */
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
	x = 0;
	y = 0;
	return (0);
}

int			on_mouse_movement(int x, int y, t_mlx_context *ctx)
{
	printf("mouse movement at %d, %d\n", x, y);
	ctx = 0;
	return (0);
}
