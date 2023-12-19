/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 20:11:16 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 20:27:51 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - NULL
// - size_t
#include <stddef.h>

#include "libft.h"

size_t	ft_strlcat(
	char *dest,
	const char *src,
	size_t size
)
{
	size_t	src_len;
	size_t	dest_len;

	if (dest == NULL)
	{
		return (0);
	}
	dest_len = ft_strnlen(dest, size);
	if (src == NULL)
	{
		return (dest_len);
	}
	src_len = ft_strlen(src);
	if (dest_len >= size)
		return (size + src_len);
	size -= dest_len;
	dest += dest_len;
	while (*src != '\0' && --size > 0)
		*(dest++) = *(src++);
	*dest = '\0';
	return (src_len + dest_len);
}
