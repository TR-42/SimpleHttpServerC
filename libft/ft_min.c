/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_min.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 22:31:15 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/17 11:10:13 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - size_t
#include <stddef.h>

#include "libft.h"

int	ft_min(int a, int b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

long	ft_minl(long a, long b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

size_t	ft_minp(size_t a, size_t b)
{
	if (a < b)
		return (a);
	else
		return (b);
}

double	ft_minf(double a, double b)
{
	if (a < b)
		return (a);
	else
		return (b);
}
