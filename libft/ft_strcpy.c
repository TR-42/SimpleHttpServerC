/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:26:25 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 20:27:37 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - NULL
#include <stddef.h>

#include "libft.h"

char	*ft_strcpy(
	char *dst,
	const char *src
)
{
	char	*dst_top;

	if (dst == NULL || src == NULL)
		return (NULL);
	dst_top = dst;
	while (*src != '\0')
		*dst++ = *src++;
	*dst = '\0';
	return (dst_top);
}
