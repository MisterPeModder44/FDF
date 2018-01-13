/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   maps.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/01/13 14:53:35 by yguaye            #+#    #+#             */
/*   Updated: 2018/01/13 17:30:06 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft_base/stringft.h>
#include <libft_base/io.h>
#include <stdio.h>
#include "maps.h"

static t_map		*new_map(void)
{
	t_map			*nmap;

	if (!(nmap = (t_map *)malloc(sizeof(t_map))))
		return (NULL);
	nmap->base = NULL;
	nmap->proj = NULL;
	nmap->name = NULL;
	nmap->prev = nmap;
	nmap->next = nmap;
	return (nmap);
}

char				*file_basename(char *path)
{
	char			**tab;
	int				i;
	char			*ret;

	if (!(tab = ft_strsplit(path, '/')))
		return (ft_strdup("<empty_name>"));
	i = 0;
	while (tab[i + 1])
		++i;
	ret = ft_strdup(tab[i]);
	ft_strtabdel(&tab);
	return (ret);
}

t_bool				add_map_file(t_map **maps, char *path)
{
	t_map			*nmap;

	if (!(nmap = new_map()))
		return (FALSE);
	if (!*maps)
		*maps = nmap;
	else
	{
		nmap->prev = (*maps)->prev;
		(*maps)->prev->next = nmap;
		nmap->next = *maps;
		(*maps)->prev = nmap;
		*maps = nmap;
	}
	printf("address: %lx, prev: %lx, next: %lx\n", (unsigned long)nmap, (unsigned long)nmap->prev, (unsigned long)nmap->next);
	if (!(nmap->base = read_fdf_file(path)))
		return (FALSE);
	nmap->name = file_basename(path);
	return (TRUE);
}

void				del_maps(t_map **maps)
{
	t_map			*iter;

	ft_putstr("name: ");
	printf("%lx", (unsigned long)*maps);
	ft_putendl("");
	iter = (*maps)->next;
	while (iter && iter != *maps)
	{
		delete_vectab(&iter->base);
		delete_vectab(&iter->proj);
		ft_strdel(&iter->name);
		free(iter);
		iter = iter->next;
		iter->prev = NULL;
	}
	delete_vectab(&iter->base);
	delete_vectab(&iter->proj);
	ft_strdel(&iter->name);
	free(iter);
	*maps = NULL;

}
