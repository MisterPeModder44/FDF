/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   events.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/14 11:14:31 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/16 15:16:44 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EVENTS_H
# define EVENTS_H

# include "fdf.h"

# define X11_BUTTON1MASK (1L << 8)
# define X11_BUTTON2MASK (1L << 9)
# define X11_STRUCTURENOTIFYMASK (1L << 17)
# define X11_MOTIONNOTIFY 6
# define X11_DESTROYNOTIFY 17

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define Z_KEY 6
# define UP_KEY 126
# define LEFT_KEY 123
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define PLUS_KEY 69
# define MINUS_KEY 78
# define BRACKET_LEFT_KEY 33
# define BRACKET_RIGHT_KEY 30

# define SCROLL_UP_KEY 4
# define SCROLL_DOWN_KEY 5

/*
   typedef struct		s_key_status
   {
   int				mouse_x;
   int				mouse_y;
   int				mouse_button;
   }					t_key_status;
   */

int			on_key_released(int key, t_mlx_context *ctx);
int			on_close_window(t_mlx_context *ctx);
int			on_mouse_pressed(int button, int x, int y, t_mlx_context *ctx);
int			on_mouse_movement(int x, int y, t_mlx_context *ctx);

#endif
