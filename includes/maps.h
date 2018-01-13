/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:45:54 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/13 15:51:33 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAPS_H
# define MAPS_H

# include "fdf.h"

t_vectab			*read_fdf_file(char *path);
t_bool				add_map_file(t_map **maps, char *path);
void				del_maps(t_map **maps);

#endif
