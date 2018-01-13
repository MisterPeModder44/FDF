/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:21:03 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/13 17:30:37 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <libft_base/base.h>
#include <libft_math/vectors.h>
#include "fdf.h"
#include "maps.h"
#include "transform.h"
#include <libft_base/io.h>

void		quit_fdf(t_mlx_context *ctx, const char *reason)
{
	if (ctx)
		mlx_destroy_window(ctx->mlx, ctx->win);
	if (reason)
		ft_putendl_fd(reason, 2);
	if (ctx && ctx->img)
		mlx_destroy_image(ctx->mlx, ctx->img);
	exit(reason != NULL);
}

float		to_rad(float angle)
{
	float	pi;

	pi = M_PI;
	return ((angle * pi) / 180.0f);
}

void		transform_projection(t_mlx_context *ctx)
{
	project(ctx->curr->base, &ctx->curr->proj, 10.0f, ctx->screen_dist);
	translate(ctx->curr->proj, ctx->width / 2, ctx->height / 2, 0);
}

static void	on_key_released(int key, t_mlx_context *ctx)
{
	if (key == ESC_KEY)
	{
		ft_putendl("test");
		del_maps(&(ctx->maps));
		printf("after\n");
		fflush(stdout);
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
	else if (key == UP_KEY)
		rotate_mx(ctx->curr->base, to_rad(-90));
	else if (key == LEFT_KEY)
		rotate_y(ctx->curr->base, to_rad(-90));
	else if (key == DOWN_KEY)
		rotate_mx(ctx->curr->base, to_rad(90));
	else if (key == RIGHT_KEY)
		rotate_y(ctx->curr->base, to_rad(90));
	else if (key == PLUS_KEY)
		translate(ctx->curr->base, 0, 0, -1);
	//ctx->screen_dist += 0.1f;
	else if (key == MINUS_KEY)
		translate(ctx->curr->base, 0, 0, 1);
	//ctx->screen_dist -= 0.1f;
	transform_projection(ctx);
	put_fdf_render(ctx, ctx->curr->proj);
}

void			printvec(t_vectab *vectab)
{
	uint32_t	ty;
	uint32_t	tx;

	ty = 0;
	while (ty < vectab->height)
	{
		tx = 0;
		while (tx < vectab->width)
		{
			printf("[%f, %f, %f]\n", *vectab->tab[ty][tx]->x, *vectab->tab[ty][tx]->y, *vectab->tab[ty][tx]->z);
			++tx;
		}
		++ty;
	}
}

static void	init_window(t_mlx_context *ctx)
{
	ctx->screen_dist = 1.0f;
	ctx->mlx = mlx_init();
	ctx->width = 2568;
	ctx->height = 1400;
	ctx->win = mlx_new_window(ctx->mlx, ctx->width, ctx->height,
			"- Fil De Fer -");
	ctx->img = NULL;
	mlx_key_hook(ctx->win, (int (*)())&on_key_released, &ctx);
}

int			main(int ac, char **av)
{
	t_mlx_context	ctx;
	int				arg;

	if (ac < 2)
		quit_fdf(NULL, "fdf: too few arguments!");
	init_window(&ctx);
	arg = 0;
	while (++arg < ac)
	{
		if (add_map_file(&ctx.maps, av[arg]) == FALSE)
			quit_fdf(NULL, "fdf: could not read file!");
	}
	printf("name 0: %s\nname 1: %s\nname 2: %s\nbeg: %s\n", ctx.maps->name, ctx.maps->next->name, ctx.maps->next->next->name, ctx.maps->next->next->next->name);
	fflush(stdout);
	ctx.curr = ctx.maps->prev;
	rotate_x(ctx.curr->base, to_rad(225.0));
	translate(ctx.curr->base, 0, 0, 25);
	scale(ctx.curr->base, 100, 100, 1);
	translate(ctx.curr->base, -(int)((ctx.curr->base->width - 1) * 100 / 2), 0, 0);
	transform_projection(&ctx);
	put_fdf_render(&ctx, ctx.curr->proj);
	mlx_loop(ctx.mlx);
	return (0);
}
