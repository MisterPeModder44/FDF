/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   args.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/17 09:41:08 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/17 10:09:21 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_base/stringft.h>
#include "fdf.h"
#include "maps.h"

static void		parse_arg_param(t_mlx_context *ctx, char *arg, int *mode)
{
	uint32_t		num;

	if (arg[0] == '-')
		quit_fdf(NULL, "fdf: size cannot be negative");
	if (!(num = (uint32_t)ft_atoi(arg)))
		quit_fdf(NULL, "fdf: null or invalid size");
	if (*mode & PWIDTH)
		ctx->width = num;
	else
		ctx->height = num;
	*mode = NO_ARGS;
}

void			parse_arg(t_mlx_context *ctx, char *arg, int *mode)
{
	if (arg[0] == '-' && arg[1] == '-')
	{
		if (*mode & PARSING)
			quit_fdf(NULL, "fdf: no size specified");
		if (ft_strequ(arg, "--width"))
			*mode |= PWIDTH;
		else if (!ft_strequ(arg, "--height"))
			quit_fdf(NULL, "fdf: invalid argument");
		*mode |= PARSING;
	}
	else if (*mode & PARSING)
		parse_arg_param(ctx, arg, mode);
	else
	{
		if (add_map_file(&ctx->maps, arg) == FALSE)
			quit_fdf(NULL, "fdf: could not read file!");
		*mode |= HAS_MAP;
	}
}
