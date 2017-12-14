/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 14:11:27 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/14 16:30:38 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <mlx.h>
#include <stdlib.h>
#include <stdio.h>
#include "libft_base/base.h"
#include "fdf.h"
#include "buttons.h"

void			on_prgm_tick(void *param)
{
	t_mlx_context	*context;
	t_list			*widget;
	t_mlx_button	*button;
	int				pos[2];

	context = (t_mlx_context *)param;
	widget = context->widgets;
	while (widget)
	{
		if (widget->content_size == BUTTON)
		{
			button = (t_mlx_button *)widget->content;
			pos[0] = 0;
			while (pos[0] < button->w)
			{
				pos[1] = 0;
				while (pos[1] < button->h)
					mlx_pixel_put(context->mlx, context->win,
							pos[0] + button->x,
							pos[1] + button->y, button->color_idle);
			}
		}
		widget = widget->next;
	}
}

void			on_key_pressed(int keycode, void *param)
{
	t_mlx_context	*context;

	context = (t_mlx_context *)param;
	if (keycode == 53)
	{
		mlx_destroy_window(context->mlx, context->win);
		exit(0);
	}
}

int				main(int argc, char **argv)
{
	t_mlx_context	context;
	t_mlx_button	*button;

	argv++;
	if (argc == 2)
	{
		context.widgets = NULL;
		context.mlx = mlx_init();
		context.win = mlx_new_window(context.mlx, 1600, 900, "FDF Prototype");
		mlx_key_hook(context.win, (int (*)())&on_key_pressed, &context);
		button = set_button_colors(create_mlx_button(200, 150), 0x00999999,
				0x00555555);
		add_mlx_button(&context, button, 550, 550);
		mlx_loop_hook(context.win, (int (*)())&on_prgm_tick, &context);
		mlx_loop(context.mlx);
	}
	return (0);
}
