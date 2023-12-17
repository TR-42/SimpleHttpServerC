/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_remove.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:36:24 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/17 21:45:04 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - bool
#include <stdbool.h>

// - size_t
#include <stddef.h>

#include "libft.h"

__attribute__((nonnull))
bool	vect_remove(
	t_vect *vect,
	size_t index
)
{
	if (vect->len <= index)
		return (false);
	if ((index + 1) < vect->len)
		ft_memmove(vect_at(vect, index), vect_at(vect, index + 1),
			(vect->len - index + 1) * vect->elemsize);
	vect->len -= 1;
	return (true);
}
