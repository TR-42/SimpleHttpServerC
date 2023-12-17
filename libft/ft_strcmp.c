/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strcmp.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:46:58 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/18 00:47:40 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>

int	ft_strcmp(
	const char *a,
	const char *b
)
{
	while (*a != '\0' && *b != '\0')
	{
		if (*a != *b)
			break ;
		a++;
		b++;
	}
	return ((unsigned char)*a - (unsigned char)*b);
}
