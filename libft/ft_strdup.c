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

static char	*_ft_strndup(
	const char *s1,
	size_t s1_len
)
{
	char	*p_ret;
	size_t	i;

	p_ret = (char *)malloc(s1_len + 1);
	if (p_ret == NULL)
		return (NULL);
	i = 0;
	if (s1 != NULL)
	{
		while (i < s1_len && s1[i] != '\0')
		{
			p_ret[i] = s1[i];
			i++;
		}
	}
	p_ret[i] = '\0';
	return (p_ret);
}

char	*ft_strdup(
	const char *s1
)
{
	size_t	s1_len;

	s1_len = ft_strlen(s1);
	return (_ft_strndup(s1, s1_len));
}

char	*ft_strndup(
	const char *s1,
	size_t s1_len
)
{
	s1_len = ft_strnlen(s1, s1_len);
	return (_ft_strndup(s1, s1_len));
}

char	*ft_strdup_trim(
	const char *s1
)
{
	size_t	s1_len;

	s1_len = 0;
	if (s1 != NULL)
	{
		while (ft_isspace(*s1))
			s1++;
		s1_len = ft_strlen(s1);
		while (0 < s1_len && ft_isspace(s1[s1_len - 1]))
			s1_len--;
	}
	s1_len = ft_strnlen(s1, s1_len);
	return (_ft_strndup(s1, s1_len));
}
