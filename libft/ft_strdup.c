/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 04:23:43 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/18 00:23:16 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - malloc
// - size_t
#include <stdlib.h>

#include "libft.h"

char	*ft_strdup(
	const char *s1
)
{
	size_t	s1_len;
	char	*p_ret;
	char	*p_ret_top;

	s1_len = ft_strlen(s1);
	p_ret = (char *)malloc(s1_len + 1);
	p_ret_top = p_ret;
	if (p_ret == NULL)
		return (NULL);
	if (s1 != NULL)
	{
		while (*s1 != '\0')
			*p_ret++ = *s1++;
	}
	*p_ret = '\0';
	return (p_ret_top);
}
