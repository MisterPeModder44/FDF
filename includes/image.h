/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:43:55 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/02 16:13:02 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stdint.h>
# include "fdf.h"

typedef union		u_color
{
	int32_t			value;
	int8_t			bytes[4];
}					t_color;

typedef struct		s_image
{
	char			*data;
	int				bpp;
	int				slen;
	int				endian;
	t_mlx_context	*ctx;
}					t_image;


int8_t		*colchan_r(t_image *img, t_color *c)
{
	return (img->endian ? c->bytes + 1 : c->bytes + 2);
}

int8_t		*colchan_g(t_image *img, t_color *c)
{
	return (img->endian ? c->bytes + 2 : c->bytes + 1);
}

int8_t		*colchan_b(t_image *img, t_color *c)
{
	return (img->endian ? c->bytes + 3 : c->bytes);
}

void				img_pixel_put(t_image *img, const int x, const int y,
		const t_color *color);

void				getProj(t_image *img);

#endif
