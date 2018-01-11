/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:19:45 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/11 16:16:05 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# define ESC_KEY 53
# define W_KEY 13
# define A_KEY 0
# define S_KEY 1
# define D_KEY 2
# define UP_KEY 126
# define LEFT_KEY 123
# define DOWN_KEY 125
# define RIGHT_KEY 124
# define PLUS_KEY 69
# define MINUS_KEY 78

# include <stdint.h>
# include <libft_base/list.h>
# include <libft_math/vectors.h>

typedef struct		s_vectab
{
	t_vec3f			***tab;
	uint32_t		width;
	uint32_t		height;
}					t_vectab;

typedef struct		s_mlx_context
{
	void			*mlx;
	void			*win;
	uint32_t		width;
	uint32_t		height;
	void			*img;
	t_vectab		*vectab;
	t_vectab		*projection;
	float			screen_dist;
}					t_mlx_context;

void				quit_fdf(t_mlx_context *ctx, const char *reason);
void				put_fdf_render(t_mlx_context *ctx, t_vectab *tab);

t_vectab			*read_fdf_file(char *path);
void				delete_vector_list(t_list **veclst);

t_vectab			*new_vectab(uint32_t width, uint32_t height);
void				vectab_copy(const t_vectab *src, t_vectab *dst);
void				delete_vectab(t_vectab **vectab);

#endif
