/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   image.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:43:55 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/03 18:50:19 by yguaye           ###   ########.fr       */
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

int8_t				*colchan_r(t_image *img, t_color *c);

int8_t				*colchan_g(t_image *img, t_color *c);

int8_t				*colchan_b(t_image *img, t_color *c);

void				img_pixel_put(t_image *img, const int x, const int y,
		const t_color *color);

#endif
