/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/17 22:35:12 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/17 23:55:05 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - NULL
// - size_t
#include <stddef.h>

#include "libft.h"

#define MIN_BASE 2
#define MAX_BASE 36

static size_t	_get_value(
	char c
)
{
	if (ft_isdigit(c))
		return (c - '0');
	if (ft_isupper(c))
		return (c - 'A' + 10);
	else
		return (c - 'a' + 10);
}

static bool	_is_valid_char(
	char c,
	unsigned char base
)
{
	if (ft_isalnum(c))
		return (_get_value(c) < base);
	else
		return (false);
}

static bool	_set_if_can_add(
	size_t *ret,
	unsigned char base,
	unsigned char c_v,
	size_t max
)
{
	size_t	tmp;

	if (!can_mulp(*ret, base))
		return (false);
	tmp = *ret * base;
	if (!can_add(*ret * base, c_v))
		return (false);
	tmp += c_v;
	if (max < *ret)
		return (false);
	*ret = tmp;
	return (true);
}

__attribute__((nonnull(1)))
size_t	ft_atop(
	const char *str,
	const char **endptr,
	unsigned char base,
	size_t max
)
{
	const char		*_endptr;
	size_t			ret;
	unsigned char	c_v;

	if (base < MIN_BASE || MAX_BASE < base)
		return (0);
	if (endptr == NULL)
		endptr = &_endptr;
	*endptr = str;
	ret = 0;
	while (ft_isspace(**endptr))
		(*endptr)++;
	while (_is_valid_char(**endptr, base) && ret < max)
	{
		c_v = _get_value(**endptr);
		if (!_set_if_can_add(&ret, base, c_v, max))
			break ;
		(*endptr)++;
	}
	return (ret);
}
