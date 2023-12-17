/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:24:20 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/18 00:19:59 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - NULL
// - size_t
#include <stddef.h>

#include "libft.h"

size_t	ft_strlen(
	const char *str
)
{
	size_t	len;

	if (str == NULL)
		return (0);
	len = 0;
	while (*str != '\0')
	{
		str++;
		len++;
	}
	return (len);
}
