/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 14:21:03 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/04 08:29:45 by yguaye           ###   ########.fr       */
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

static void	on_key_released(int key, t_mlx_context *ctx)
{
	if (key == 53)
		quit_fdf(ctx, NULL);
	else
	{
		ft_putstr("key: ");
		ft_putnbr(key);
		ft_putendl("");
	}
}

//TEMPORARY
static void printvec(t_list *lst)
{
	t_vec3f	*vec;

	vec = (t_vec3f *)lst->content;
	printf("[%f, %f, %f]\n", *vec->x, *vec->y, *vec->z);
}

int			main(int ac, char **av)
{
	t_list			*lst;
	t_mlx_context	ctx;

	if (ac != 2)
		quit_fdf(NULL, "fdf: wrong number of arguments!");
	if (!(lst = read_fdf_file(av[1])))
		quit_fdf(NULL, NULL);
	scale(lst, 2, 0, 0);
	ft_lstiter(lst, &printvec);
	delete_vector_list(&lst);
	ctx.mlx = mlx_init();
	ctx.width = 800;
	ctx.height = 450;
	ctx.win = mlx_new_window(ctx.mlx, ctx.width, ctx.height, "- Fil De Fer -");
	ctx.img = NULL;
	mlx_key_hook(ctx.win, (int (*)())&on_key_released, &ctx);
	put_fdf_render(&ctx);
	mlx_loop(ctx.mlx);
	return (0);
}
