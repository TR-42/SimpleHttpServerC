/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   http_header_list_add.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:43:44 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/18 01:05:29 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - bool
#include <stdbool.h>

// - size_t
#include <stddef.h>

#include <libft.h>

#include <http_header_list.h>

__attribute__((nonnull))
static size_t	_get_value_count(
	const char *const *arr2d
)
{
	size_t	count;

	count = 0;
	while (arr2d[count] != NULL)
		count++;
	return (count);
}

__attribute__((nonnull))
static bool	_push_value(
	t_http_header_list *dst,
	const char *value
)
{
	size_t	count;
	char	**tmp;

	if (dst->value_list == NULL)
		return (false);
	count = _get_value_count((const char *const *)dst->value_list);
	if (dst->value_list_cap == count)
	{
		tmp = ft_calloc_move(
				(void**)&(dst->value_list),
				count * sizeof(char *),
				count + HTTP_HEADER_LIST_CAP_STEP,
				sizeof(char *)
				);
		if (tmp == NULL)
			return (false);
		dst->value_list_cap += HTTP_HEADER_LIST_CAP_STEP;
		dst->value_list = tmp;
	}
	dst->value_list[count] = ft_strdup(value);
	return (dst->value_list[count] != NULL);
}

__attribute__((nonnull))
bool	http_header_list_add(
	t_http_header_list **list,
	const char *key,
	const char *value
)
{
	t_http_header_list	*dst;

	dst = http_header_list_get(*list, key);
	if (dst == NULL)
	{
		dst = http_header_list_new(key, value);
		if (dst == NULL)
			return (false);
		dst->next = *list;
		*list = dst;
		return (true);
	}
	else
		return (_push_value(dst, value));
}
