/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:08:50 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/16 17:14:25 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <libft_math/vectors.h>
#include <libft_base/stringft.h>
#include "fdf.h"
#include "image.h"
#include "line.h"

static void			draw_links(t_image *img, t_vectab *tab, t_color *col,
		int draw_diags)
{
	uint32_t	ty;
	uint32_t	tx;
	t_bool		f1;
	t_bool		f2;

	ty = 0;
	while (ty < tab->height)
	{
		tx = 0;
		while (tx < tab->width)
		{
			if ((f1 = *tab->tab[ty][tx]->z > 0 && tx + 1 < tab->width))
				draw_between(img, tab->tab[ty][tx], tab->tab[ty][tx + 1], col);
			if ((f2 = *tab->tab[ty][tx]->z > 0 && ty + 1 < tab->height))
				draw_between(img, tab->tab[ty][tx], tab->tab[ty + 1][tx], col);
			if (draw_diags && f1 && f2)
			{
				draw_between(img, tab->tab[ty][tx], tab->tab[ty + 1][tx + 1],
						col);
			}
			++tx;
		}
		++ty;
	}
}

static void			put_hints(t_mlx_context *ctx)
{
	size_t			nlen;

	nlen = ft_strlen(ctx->curr->name);
	mlx_string_put(ctx->mlx, ctx->win, ctx->width - (nlen * 10), 0,
			0x00FFFFFF, ctx->curr->name);
	mlx_string_put(ctx->mlx, ctx->win, 0, 0, 0x00FFFFFF, "Press <esc> to quit");
}

void				put_fdf_render(t_mlx_context *ctx, t_vectab *tab)
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
	color.value = 0x00b35900;
	draw_links(&img, tab, &color, ctx->draw_diags);
	mlx_put_image_to_window(ctx->mlx, ctx->win, ctx->img, 0, 0);
	put_hints(ctx);
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
