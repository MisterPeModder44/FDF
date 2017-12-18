/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:43:55 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/18 16:29:10 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef IMAGE_H
# define IMAGE_H

# include <stdint.h>

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

# define COLCHAN_A(i, c) (i->endian ? c->bytes : c->bytes + 3)
# define COLCHAN_R(i, c) (i->endian ? c->bytes + 1 : c->bytes + 2)
# define COLCHAN_G(i, c) (i->endian ? c->bytes + 2 : c->bytes + 1)
# define COLCHAN_B(i, c) (i->endian ? c->bytes + 3 : c->bytes)

void				pixel_put(t_image *img, int x, int y, int32_t color)
{
	int				pos;

	pos = (x + y * img->slen) * 4;

}

#endif
