/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:21:01 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/14 16:34:23 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "buttons.h"
#include <stdlib.h>

t_mlx_button			*create_mlx_button(int width, int height)
{
	t_mlx_button		*button;

	if (!(button = (t_mlx_button *)malloc(sizeof(t_mlx_button))))
		return (NULL);
	button->w = width;
	button->h = height;
	button->x = 0;
	button->y = 0;
	button->color_idle = 0x00000000;
	button->color_clicked = 0x00000000;
	button->state = BUTTON_IDLE;
	return (button);
}

t_mlx_button			*set_button_colors(t_mlx_button *button,
		int idle, int clicked)
{
	if (button)
	{
		button->color_idle = idle;
		button->color_clicked = clicked;
	}
	return (button);
}

void					add_mlx_button(t_mlx_context *context,
		t_mlx_button *button, int x, int y)
{
	t_list				*widget;

	button->x = x;
	button->y = y;
	if (!(widget = ft_lstnew(button, BUTTON)))
		return ;
	ft_lstadd(&context->widgets, widget);
}

static void				del_button(void *button, size_t type)
{
	free(button);
	type = 0;
}

void					delete_mlx_button(t_mlx_context *context,
		t_mlx_button *button)
{
	t_list				*widget;
	t_list				*prev;

	widget = context->widgets;
	prev = NULL;
	while (widget)
	{
		if (widget->content_size == BUTTON && widget->content == button)
		{
			if (prev)
				prev->next = widget->next;
			else
				context->widgets = context->widgets->next;
			ft_lstdelone(&widget, &del_button);
			break;
		}
		prev = widget;
		widget = widget->next;
	}
}
