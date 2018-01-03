/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:08:50 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/03 14:12:04 by yguaye           ###   ########.fr       */
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

void				img_pixel_put(t_image *img, const int x, const int y,
		const t_color *color)
{
	int				pos;

	pos = (x + y * img->slen) * img->bpp / 8;
	img->data[pos] = color->bytes[0];
	img->data[pos + 1] = color->bytes[1];
	img->data[pos + 2] = color->bytes[2];
	img->data[pos + 3] = color->bytes[3];
}
