/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 11:03:26 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/17 23:55:45 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - errno
#include <errno.h>

// - free
// - malloc
// - NULL
// - size_t
#include <stdlib.h>

#include "libft.h"

static void	*_ft_calloc_nofill(
	size_t count,
	size_t size,
	size_t *size_to_alloc
)
{
	size_t	tmp;

	if (size_to_alloc == NULL)
		size_to_alloc = &tmp;
	*size_to_alloc = 0;
	if (!can_mulp(count, size))
	{
		errno = ENOMEM;
		return (NULL);
	}
	*size_to_alloc = count * size;
	if (*size_to_alloc == 0)
		*size_to_alloc = 1;
	return (malloc(*size_to_alloc));
}

void	*ft_calloc_nofill(
	size_t count,
	size_t size
)
{
	return (_ft_calloc_nofill(count, size, NULL));
}

void	*ft_calloc(
	size_t count,
	size_t size
)
{
	void	*ptr;
	size_t	size_to_alloc;

	ptr = _ft_calloc_nofill(count, size, &size_to_alloc);
	if (ptr != NULL)
		ft_bzero(ptr, size_to_alloc);
	return (ptr);
}

void	*ft_calloc_move(
	void **src,
	size_t src_bytes,
	size_t count,
	size_t size
)
{
	void	*ptr;
	size_t	size_to_alloc;

	ptr = _ft_calloc_nofill(count, size, &size_to_alloc);
	if (ptr != NULL && src != NULL && *src != NULL)
	{
		ft_memcpy(ptr, *src, ft_minp(src_bytes, size_to_alloc));
		free(*src);
		*src = NULL;
	}
	return (ptr);
}
