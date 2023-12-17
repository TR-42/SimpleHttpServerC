/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   http_header_list_get.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:45:49 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/18 01:07:34 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <http_header_list.h>

t_http_header_list	*http_header_list_get(
	t_http_header_list *list,
	const char *key
)
{
	while (list != NULL)
	{
		if (ft_strcmp(list->key, key) == 0)
			return (list);
		list = list->next;
	}
	return (NULL);
}
