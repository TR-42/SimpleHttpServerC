/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dispose_httpreq.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:59:12 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/20 00:02:42 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - NULL
#include <stddef.h>

// - free
#include <stdlib.h>

#include <libft.h>

#include <ft_httpserv.h>

__attribute__((nonnull))
void	ft_httpserv_dispose_httpreq(
	t_httpreq *req
)
{
	if (req->method != NULL)
		free(req->method);
	if (req->path != NULL)
		free(req->path);
	if (req->version != NULL)
		free(req->version);
	if (req->header_list != NULL)
		http_header_list_free(&(req->header_list));
	if (req->body != NULL)
		free(req->body);
	ft_bzero(req, sizeof(t_httpreq));
}
