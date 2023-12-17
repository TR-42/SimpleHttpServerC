/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   http_header_list_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:27:16 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/18 01:05:56 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - free
// - NULL
#include <stdlib.h>

#include <libft.h>

#include <http_header_list.h>

static void	_http_header_list_free(
	t_http_header_list *list
)
{
	t_http_header_list	*next;

	while (list != NULL)
	{
		next = list->next;
		free(list->key);
		free2d((void ***)&(list->value_list));
		free(list);
		list = next;
	}
}

void	http_header_list_free(
	t_http_header_list **list
)
{
	if (list == NULL || *list == NULL)
		return ;
	_http_header_list_free(*list);
	*list = NULL;
}
