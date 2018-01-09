/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:08:50 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/09 17:40:32 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft_math/vectors.h>
#include "fdf.h"
#include "image.h"
#include "line.h"

void				put_fdf_render(t_mlx_context *ctx, t_list *vectors)
{
	t_image			img;
	t_color			color;

	if (ctx->img)
		mlx_destroy_image(ctx->mlx, ctx->img);
	ctx->img = mlx_new_image(ctx->mlx, ctx->width, ctx->height);
	img.ctx = ctx;
	img.data = mlx_get_data_addr(ctx->img, &img.bpp, &img.slen, &img.endian);
	if (img.bpp < 32)
		quit_fdf(ctx, "fdf: unsupported image format.");
	color.value = 0x00FFFFFF;
	while (vectors)
	{
		if (vectors->next)
			draw_between(&img, (t_vec3f *)vectors->content,
					(t_vec3f *)vectors->next->content, &color);
		vectors = vectors->next;
	}
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img, 0, 0);
}

void				img_pixel_put(t_image *img, const int x, const int y,
		const t_color *color)
{
	int				pos;

	if (x < 0 || y < 0 ||
			(uint32_t)x >= img->ctx->width || (uint32_t)y >= img->ctx->height)
		return ;
	pos = (x + y * img->ctx->width) * img->bpp / 8;
	img->data[pos] = color->bytes[0];
	img->data[pos + 1] = color->bytes[1];
	img->data[pos + 2] = color->bytes[2];
	img->data[pos + 3] = color->bytes[3];
}

int8_t				*colchan_r(t_image *img, t_color *c)
{
	return (img->endian ? c->bytes + 1 : c->bytes + 2);
}

int8_t				*colchan_g(t_image *img, t_color *c)
{
	return (img->endian ? c->bytes + 2 : c->bytes + 1);
}

int8_t				*colchan_b(t_image *img, t_color *c)
{
	return (img->endian ? c->bytes + 3 : c->bytes);
}
