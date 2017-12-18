/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrix.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 00:22:30 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/18 03:43:36 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MATRIX_H
# define MATRIX_H

# include "libft_base/base.h"

typedef struct		s_matrix
{
	int				width;
	int				height;
	t_list			*verts;
}					t_matrix;

int					parse_matrix_line(char *line, t_matrix *m);
t_matrix			*read_matrix(char *file);
void				delete_matrix(t_matrix **matrix);

#endif
