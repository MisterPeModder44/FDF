/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:19:45 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/14 16:29:17 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include "libft_base/base.h"

typedef enum			e_mlx_widgets
{
	BUTTON,
	LABEL,
}						t_mlx_widget_type;

typedef struct			s_mlx_context
{
	void				*mlx;
	void				*win;
	t_list				*widgets;
}						t_mlx_context;

void					free_widget();

#endif
