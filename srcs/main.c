/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:11:27 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/14 18:38:53 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "fdf.h"

void				on_key_pressed(int keycode, void *param)
{
	t_mlx_context	*context;

	context = (t_mlx_context *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(context->mlx, context->win);
		exit(0);
	}
}

#include <stdio.h>

int					main(int argc, char **argv)
{
	t_mlx_context	context;
	t_point			p1;
	t_point			p2;

	argv++;
	if (argc == 7)
	{
		context.mlx = mlx_init();
		context.win = mlx_new_window(context.mlx, 1600,
				900, "FDF Prototype");
		p1.x = 100;
		p1.y = 100;
		p2.x = 1500;
		p2.y = 800;
		draw_line(&context, &p1, &p2);
		mlx_key_hook(context.win, (int (*)())&on_key_pressed, &context);
		mlx_loop(context.mlx);
	}
	else
		ft_putendl("Wrong number of args: 6 required !");
	return (0);
}
