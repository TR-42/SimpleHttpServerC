/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_req.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:21:15 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 20:00:04 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <ft_httpserv.h>

t_httpreq	ft_httpserv_parse_req(
	int fd
)
{
	t_httpreq	req;
	t_gnl_state	state;

	state = gen_gnl_state(fd, 4096);
	ft_bzero(&req, sizeof(req));
	req.fd = -1;
	if (state.buf == NULL)
		return (req);
	dispose_gnl_state(&state);
	req.fd = fd;
	return (req);
}
