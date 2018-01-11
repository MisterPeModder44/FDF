/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:21:03 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/11 14:30:00 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <math.h>
#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include <libft_base/base.h>
#include <libft_math/vectors.h>
#include "fdf.h"
#include "transform.h"

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

static void	on_key_released(int key, t_mlx_context *ctx)
{
	if (key == ESC_KEY)
	{
		delete_vectab(&ctx->vectab);
		delete_vectab(&ctx->projection);
		quit_fdf(ctx, NULL);
	}
	else if (key == W_KEY)
		translate(ctx->vectab, 0, -1000, 0);
	else if (key == A_KEY)
		translate(ctx->vectab, -1000, 0, 0);
	else if (key == S_KEY)
		translate(ctx->vectab, 0, 1000, 0);
	else if (key == D_KEY)
		translate(ctx->vectab, 1000, 0, 0);
	else if (key == UP_KEY)
		rotate_x(ctx->vectab, to_rad(-1));
	else if (key == LEFT_KEY)
		rotate_y(ctx->vectab, to_rad(-1));
	else if (key == DOWN_KEY)
		rotate_x(ctx->vectab, to_rad(1));
	else if (key == RIGHT_KEY)
		rotate_y(ctx->vectab, to_rad(1));
	else if (key == PLUS_KEY)
		translate(ctx->vectab, 0, 0, -1);
	//ctx->screen_dist += 0.1f;
	else if (key == MINUS_KEY)
		translate(ctx->vectab, 0, 0, 1);
	//ctx->screen_dist -= 0.1f;
	printf("key: %d\n", key);
	project(ctx->vectab, &ctx->projection, 10.0f, ctx->screen_dist);
	translate(ctx->projection, 1284, 700, 0);
	//scale(ctx->projection, 100, 100, 0);
	//translate(ctx->projection, 500, 200, 0);
	put_fdf_render(ctx);
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

int			main(int ac, char **av)
{
	t_mlx_context	ctx;

	if (ac != 2)
		quit_fdf(NULL, "fdf: wrong number of arguments!");
	if (!(ctx.vectab = read_fdf_file(av[1])))
		quit_fdf(NULL, NULL);
	ctx.projection = NULL;
	ctx.screen_dist = 1.0f;
	//printvec(ctx.vectab);
	//fflush(stdout);
	rotate_x(ctx.vectab, to_rad(200.0));
	rotate_y(ctx.vectab, to_rad(0.0));
	translate(ctx.vectab, 0, 0, 25);
	//translate(ctx.vectab, 100, 100, 200);
	scale(ctx.vectab, 100, 100, 1);
	project(ctx.vectab, &ctx.projection, 10.0f, ctx.screen_dist);
	translate(ctx.projection, 1284, 700, 0);
	printf("SEEEEEEEEEEEEEEEGFAULT\n");
	fflush(stdout);
	printvec(ctx.projection);
	fflush(stdout);
	//translate(ctx.projection, 500, 200, 0);
	//ft_lstiter(ctx.vectors, &printvec);
	ctx.mlx = mlx_init();
	ctx.width = 2568;
	ctx.height = 1400;
	ctx.win = mlx_new_window(ctx.mlx, ctx.width, ctx.height, "- Fil De Fer -");
	ctx.img = NULL;
	mlx_key_hook(ctx.win, (int (*)())&on_key_released, &ctx);
	put_fdf_render(&ctx);
	mlx_loop(ctx.mlx);
	return (0);
}
