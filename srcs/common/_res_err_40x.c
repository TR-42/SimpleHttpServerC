/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _res_err_40x.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:33:21 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 23:35:57 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_httpserv.h>

#include "_res_err.h"

bool	_res_err_400(int sockfd, const char *msg)
{
	ft_httpserv_send_simple_res(sockfd, HTTP_STATUS_BAD_REQUEST, msg);
	return (false);
}
