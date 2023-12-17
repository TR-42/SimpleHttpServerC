/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   http_header_list.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:08:43 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/18 01:07:19 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef HTTP_HEADER_LIST_H
# define HTTP_HEADER_LIST_H

// - bool
# include <stdbool.h>

// - size_t
# include <stddef.h>

# define HTTP_HEADER_LIST_CAP_STEP 8

typedef struct s_http_header_list	t_http_header_list;

typedef struct s_http_header_list
{
	char				*key;
	char				**value_list;
	size_t				value_list_cap;
	t_http_header_list	*next;
}	t_http_header_list;

bool				http_header_list_add(
						t_http_header_list **list,
						const char *key,
						const char *value
						)
					__attribute__((nonnull))
					;

void				http_header_list_free(
						t_http_header_list **list
						)
					;

t_http_header_list	*http_header_list_get(
						t_http_header_list *list,
						const char *key
						)
					;

t_http_header_list	*http_header_list_new(
						const char *key,
						const char *value
						)
					__attribute__((nonnull))
					;

#endif
