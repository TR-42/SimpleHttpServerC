/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_http_status_msg.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:39:50 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 19:40:05 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_httpserv.h>

const char	*get_http_status_msg(
	t_http_status_code status_code
)
{
	if (status_code == HTTP_STATUS_OK)
		return ("OK");
	else if (status_code == HTTP_STATUS_BAD_REQUEST)
		return ("Bad Request");
	else if (status_code == HTTP_STATUS_NOT_FOUND)
		return ("Not Found");
	else if (status_code == HTTP_STATUS_INTERNAL_SERVER_ERROR)
		return ("Internal Server Error");
	else
		return ("Unknown");
}
