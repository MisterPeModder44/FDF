/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:19:45 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/09 17:47:34 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ESC_KEY 53

# include <stdint.h>
# include <libft_base/list.h>

typedef struct		s_mlx_context
{
	void			*mlx;
	void			*win;
	uint32_t		width;
	uint32_t		height;
	void			*img;
	t_list			*vectors;
}					t_mlx_context;

void				quit_fdf(t_mlx_context *ctx, const char *reason);
void				put_fdf_render(t_mlx_context *ctx, t_list *vectors);

t_list				*read_fdf_file(char *path);
void				delete_vector_list(t_list **list);

#endif
