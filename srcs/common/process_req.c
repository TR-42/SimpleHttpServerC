/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   process_req.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 18:58:21 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 20:26:31 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - bool
#include <stdbool.h>

// - printf
#include <stdio.h>

#include <ft_httpserv.h>

static void	_dump_httpreq(
	const t_httpreq *req
)
{
	size_t				i;
	t_http_header_list	*header_list;

	printf("method: '%s'\n", req->method);
	printf("path: '%s'\n", req->path);
	printf("version: '%s'\n", req->version);
	header_list = req->header_list;
	while (header_list != NULL)
	{
		printf("header: '%s'\n", header_list->key);
		i = 0;
		while (header_list->value_list[i] != NULL)
		{
			printf("\t[%zu]: '%s'\n", i, header_list->value_list[i]);
			i++;
		}
		header_list = header_list->next;
	}
}

bool	ft_httpserv_process_req(
	int fd
)
{
	t_httpreq	req;

	if (!ft_httpserv_parse_req(fd, &req))
	{
		ft_httpserv_dispose_httpreq(&req);
		return (true);
	}
	_dump_httpreq(&req);
	ft_httpserv_dispose_httpreq(&req);
	return (ft_httpserv_send_simple_res(fd, HTTP_STATUS_OK, NULL));
}
