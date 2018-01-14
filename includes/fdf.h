/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fdf.h                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/14 15:19:45 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/14 11:14:36 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FDF_H
# define FDF_H

# include <stdint.h>
# include <libft_base/list.h>
# include <libft_math/vectors.h>

typedef enum		e_bool
{
	FALSE = 0,
	TRUE = 1,
}					t_bool;

typedef struct		s_vectab
{
	t_vec3f			***tab;
	uint32_t		width;
	uint32_t		height;
}					t_vectab;

typedef struct		s_map
{
	t_vectab		*base;
	t_vectab		*proj;
	char			*name;
	struct s_map	*prev;
	struct s_map	*next;
}					t_map;

typedef struct		s_mlx_context
{
	void			*mlx;
	void			*win;
	uint32_t		width;
	uint32_t		height;
	void			*img;
	t_map			*maps;
	t_map			*curr;
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
