/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   http_header_list_new.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:16:26 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/18 00:42:16 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - NULL
#include <stddef.h>

#include <libft.h>

#include <http_header_list.h>

__attribute__((nonnull))
t_http_header_list	*http_header_list_new(
	const char *key,
	const char *value
)
{
	t_http_header_list	*header_list;

	header_list = ft_calloc(1, sizeof(t_http_header_list));
	if (header_list == NULL)
		return (NULL);
	header_list->key = ft_strdup(key);
	if (header_list->key == NULL)
	{
		http_header_list_free(&header_list);
		return (header_list);
	}
	header_list->value_list = ft_calloc_nofill(
			HTTP_HEADER_LIST_CAP_STEP,
			sizeof(char *)
			);
	if (header_list->value_list != NULL)
		header_list->value_list[0] = ft_strdup(value);
	if (header_list->value_list == NULL || header_list->value_list[0] == NULL)
		http_header_list_free(&header_list);
	return (header_list);
}
