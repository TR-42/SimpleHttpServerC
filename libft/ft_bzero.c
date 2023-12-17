/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/06 19:26:30 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/17 21:00:11 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - NULL
// - size_t
#include <stddef.h>

#include "libft.h"

void	ft_bzero(void *s, size_t n)
{
	char	*ptr;

	if (s == NULL || n == 0)
		return ;
	ptr = s;
	while (n-- > 0)
	{
		*ptr = 0;
		ptr++;
	}
}
