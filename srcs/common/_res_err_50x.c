/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _res_err_50x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:33:21 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 23:36:08 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_httpserv.h>

#include "_res_err.h"

bool	_res_err_500(int sockfd, const char *msg)
{
	ft_httpserv_send_simple_res(sockfd,
		HTTP_STATUS_INTERNAL_SERVER_ERROR, msg);
	return (false);
}
