/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 12:29:44 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/14 12:41:00 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "fdf.h"
#include "maps.h"
#include "transform.h"
#include "keys.h"
#include "keys.h"
#include "utils.h"

static void	on_key_r1(int key, t_mlx_context *ctx)
{
	if (key == ESC_KEY)
	{
		del_maps(&(ctx->maps));
		quit_fdf(ctx, NULL);
	}
	else if (key == W_KEY)
		translate(ctx->curr->base, 0, -1000, 0);
	else if (key == A_KEY)
		translate(ctx->curr->base, -1000, 0, 0);
	else if (key == S_KEY)
		translate(ctx->curr->base, 0, 1000, 0);
	else if (key == D_KEY)
		translate(ctx->curr->base, 1000, 0, 0);
}

void		on_key_released(int key, t_mlx_context *ctx)
{
	on_key_r1(key, ctx);
	if (key == UP_KEY)
		rotate_x(ctx->curr->base, to_rad(-90));
	else if (key == LEFT_KEY)
		rotate_y(ctx->curr->base, to_rad(-90));
	else if (key == DOWN_KEY)
		rotate_x(ctx->curr->base, to_rad(90));
	else if (key == RIGHT_KEY)
		rotate_y(ctx->curr->base, to_rad(90));
	else if (key == PLUS_KEY)
		translate(ctx->curr->base, 0, 0, -1);
	else if (key == MINUS_KEY)
		translate(ctx->curr->base, 0, 0, 1);
	else if (key == BRACKET_LEFT_KEY)
		ctx->curr = ctx->curr->prev;
	else if (key == BRACKET_RIGHT_KEY)
		ctx->curr = ctx->curr->next;
	project(ctx->curr->base, &ctx->curr->proj, ctx->screen_dist);
	translate(ctx->curr->proj, ctx->width / 2, ctx->height / 2, 0);
	put_fdf_render(ctx, ctx->curr->proj);
	printf("key: %d\n", key);
}
