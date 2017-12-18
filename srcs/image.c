/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:08:50 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/18 16:21:52 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include "fdf.h"
#include "image.h"

void				put_fdf_render(t_mlx_context *ctx)
{
	t_image			img;

	if (ctx->img)
		mlx_destroy_image(ctx->mlx, ctx->img);
	ctx->img = mlx_new_image(ctx->mlx, ctx->width, ctx->height);
	img.ctx = ctx;
	img.data = mlx_get_data_addr(ctx->img, &img.bpp, &img.slen, &img.endian);
	if (img.bpp < 32)
		quit_fdf(ctx, "fdf: unsupported image format.");
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img, 0, 0);
}
