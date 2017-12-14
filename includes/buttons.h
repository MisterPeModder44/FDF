/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   buttons.h                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:24:30 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/14 16:20:22 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUTTONS_H
# define BUTTONS_H

# include "fdf.h"
# include "libft_base/base.h"

typedef enum			e_mlx_button_state
{
	BUTTON_HIDDEN,
	BUTTON_IDLE,
	BUTTON_HOVERED,
	BUTTON_CLICKED
}						t_mlx_button_state;

typedef struct			s_mlx_button
{
	int					x;
	int					y;
	int					w;
	int					h;
	int					color_idle;
	int					color_clicked;
	t_mlx_button_state	state;
}						t_mlx_button;

t_list					*button_list(t_list *new_list);

t_mlx_button			*create_mlx_button(int width, int height);
t_mlx_button			*set_button_colors(t_mlx_button *button,
		int idle, int clicked);
void					add_mlx_button(t_mlx_context *context,
		t_mlx_button *button, int x, int y);
void					delete_mlx_button(t_mlx_context *context,
		t_mlx_button *button);


#endif
