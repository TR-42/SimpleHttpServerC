/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_set.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 01:10:41 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/17 21:46:24 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - bool
#include <stdbool.h>

// - NULL
// - size_t
#include <stddef.h>

#include "libft.h"

__attribute__((nonnull))
bool	vect_set(
	t_vect *vect,
	const void *elem,
	size_t index
)
{
	unsigned char	*p;

	if (vect->p == NULL || vect->elemsize == 0 || vect->len < index)
		return (false);
	if (vect->cap <= index
		&& !vect_reserve(vect, index + FT_VECT_EXPAND_STEP))
		return (false);
	p = vect->p;
	ft_memmove(p + (index * vect->elemsize), elem, vect->elemsize);
	if (vect->len == index)
		vect->len += 1;
	return (true);
}
