/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/19 07:57:56 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 00:59:07 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - write
// - size_t
#include <unistd.h>

// - INT_MAX
#include <limits.h>

#include "libft.h"

void	ft_putstr_fd(
	const char *s,
	int fd
)
{
	size_t	length;

	if (s == NULL)
		return ;
	while (*s != '\0')
	{
		length = ft_strnlen(s, INT_MAX);
		write(fd, s, length);
		s += length;
	}
}
