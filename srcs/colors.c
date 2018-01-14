/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   colors.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 12:03:37 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/14 12:04:13 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "image.h"

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
