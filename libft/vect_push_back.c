/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_push_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:30:13 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/17 21:41:59 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - bool
#include <stdbool.h>

// - NULL
// - size_t
#include <stddef.h>

#include "libft.h"

__attribute__((nonnull(1, 2)))
bool	vect_push_back(
	t_vect *vect,
	const void *elem,
	size_t *written_index
)
{
	size_t	index;

	index = vect->len;
	if (!vect_set(vect, elem, index))
		return (false);
	if (written_index != NULL)
		*written_index = index;
	return (true);
}
