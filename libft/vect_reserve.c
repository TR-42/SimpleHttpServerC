/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_reserve.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:32:55 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/17 21:46:35 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - bool
#include <stdbool.h>

// - NULL
// - size_t
#include <stdlib.h>

#include "libft.h"

__attribute__((nonnull))
bool	vect_reserve(
	t_vect *vect,
	size_t newcap
)
{
	void	*p_new;

	if (vect->elemsize == 0 || newcap <= vect->len)
		return (false);
	if (newcap == 0)
		p_new = NULL;
	else
	{
		p_new = ft_calloc_nofill(newcap, vect->elemsize);
		if (p_new == NULL)
			return (false);
		ft_memmove(p_new, vect->p, vect->elemsize * vect->len);
		free(vect->p);
	}
	vect->p = p_new;
	vect->cap = newcap;
	return (true);
}
