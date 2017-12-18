/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/18 00:40:20 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/18 02:55:59 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "libft_base/base.h"

int				return_error(char *s, int r)
{
	ft_putendl_fd(s, 2);
	return (r);
}

void			exit_error(char *s)
{
	perror(s);
	exit(-1);
}
