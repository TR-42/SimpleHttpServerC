/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   vect_init.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/28 00:06:47 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/17 21:44:16 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - NULL
// - size_t
#include <stddef.h>

#include "libft.h"

t_vect	vect_init(
	size_t cap,
	size_t elemsize
)
{
	t_vect	ret;

	ret.p = ft_calloc_nofill(cap, elemsize);
	if (ret.p != NULL)
	{
		ret.cap = cap;
		ret.len = 0;
		ret.elemsize = elemsize;
	}
	return (ret);
}
