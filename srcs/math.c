/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   math.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yguaye <yguaye@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/12/20 11:11:35 by yguaye            #+#    #+#             */
/*   Updated: 2017/12/20 11:42:06 by yguaye           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "math.h"

float				ft_pow(float x, int pow)
{
	if (pow == 0)
		return (1);
	else if (pow < 0)
		return (1 / ft_pow(x, -pow));
	while (--pow > 0)
		x *= x;
	return (x);
}

float				ft_tan(float x)
{
	float tmp;

	x = ft_abs(x);
	while (x >= PI * 2)
		x -= PI;
	if (x > PI)
		return (-ft_tan(x - PI));
	else if (x > PI / 2)
		return (1 / ft_tan(PI - x));
	else if (x > PI / 4)
	{
		tmp = ft_tan(x / 2);
		return ((2 * ft_tan(x / 2)) / (1 - (tmp * tmp)));
	}
	return (x + ft_pow(x, 3) / 3 + (2 * ft_pow(x, 5)) / 15 +
			(17 * ft_pow(x, 7)) / 315);
}
