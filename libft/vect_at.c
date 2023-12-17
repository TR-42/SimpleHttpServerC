/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_at.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:23:26 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/17 21:38:31 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - NULL
// - size_t
#include <stddef.h>

#include "libft.h"

__attribute__((nonnull))
void	*vect_at(
	const t_vect *vect,
	size_t index
)
{
	unsigned char	*p;

	if (vect->len <= index)
		return (NULL);
	p = vect->p;
	return (p + (vect->elemsize * index));
}
