/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:24:18 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/17 21:03:48 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - NULL
// - size_t
#include <stddef.h>

#include "libft.h"

void	*ft_memset(void *target, int val_to_set, size_t len_to_fill)
{
	unsigned char	*p_c_target;

	if (target == NULL || len_to_fill == 0)
		return (target);
	p_c_target = target;
	while (len_to_fill-- > 0)
	{
		*p_c_target = (unsigned char)val_to_set;
		p_c_target++;
	}
	return (target);
}
