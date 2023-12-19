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

#include <ft_httpserv.h>

bool	ft_httpserv_process_req(
	int fd
)
{
	t_httpreq	req;

	req = ft_httpserv_parse_req(fd);
	if (req.fd == -1)
		return (ft_httpserv_send_simple_res(fd,
				HTTP_STATUS_INTERNAL_SERVER_ERROR, NULL) || false);
	return (ft_httpserv_send_simple_res(fd, HTTP_STATUS_OK, NULL));
}
