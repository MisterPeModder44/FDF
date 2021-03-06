/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 12:29:44 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/16 18:12:23 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fdf.h"
#include "maps.h"
#include "transform.h"
#include "events.h"
#include "utils.h"

static void	on_key_r1(int key, t_mlx_context *ctx)
{
	if (key == ESC_KEY)
		on_close_window(ctx);
	else if (key == W_KEY || key == UP_KEY)
		translate(ctx->curr->base, 0, -100 * ctx->screen_dist, 0);
	else if (key == A_KEY || key == LEFT_KEY)
		translate(ctx->curr->base, -100 * ctx->screen_dist, 0, 0);
	else if (key == S_KEY || key == DOWN_KEY)
		translate(ctx->curr->base, 0, 100 * ctx->screen_dist, 0);
	else if (key == D_KEY || key == RIGHT_KEY)
		translate(ctx->curr->base, 100 * ctx->screen_dist, 0, 0);
	else if (key == Z_KEY)
		ctx->draw_diags = !ctx->draw_diags;
}

int			on_key_released(int key, t_mlx_context *ctx)
{
	on_key_r1(key, ctx);
	if (key == PLUS_KEY)
		translate(ctx->curr->base, 0, 0, -ctx->screen_dist);
	else if (key == MINUS_KEY)
		translate(ctx->curr->base, 0, 0, ctx->screen_dist);
	else if (key == BRACKET_LEFT_KEY)
		ctx->curr = ctx->curr->prev;
	else if (key == BRACKET_RIGHT_KEY)
		ctx->curr = ctx->curr->next;
	project(ctx->curr->base, &ctx->curr->proj, ctx->screen_dist);
	translate(ctx->curr->proj, ctx->width / 2, ctx->height / 2, 0);
	put_fdf_render(ctx, ctx->curr->proj);
	return (0);
}
