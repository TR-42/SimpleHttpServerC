/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_simple_res.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:03:24 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 20:10:45 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <libft.h>

#include <ft_httpserv.h>

#define BUF_SIZE 256
#define HTTP_HEADER_CONTENT_LENGTH "Content-Length"
#define HTTP_HEADER_CONTENT_TYPE "Content-Type"
#define MIME_TEXT_PLAIN "text/plain"

bool	ft_httpserv_send_simple_res(
	int sockfd,
	t_http_status_code status_code,
	const char *response_body
)
{
	char		buf[BUF_SIZE];
	size_t		body_len;

	if (response_body == NULL)
		response_body = get_http_status_msg(status_code);
	body_len = ft_strlen(response_body);
	if (!(ft_httpserv_send_status(sockfd, status_code)
			&& ft_httpserv_send_header(sockfd, HTTP_HEADER_CONTENT_LENGTH,
				ft_ptoa(body_len, buf))
			&& ft_httpserv_send_header(sockfd, HTTP_HEADER_CONTENT_TYPE,
				MIME_TEXT_PLAIN)
		))
		return (false);
	if (send(sockfd, STR_CRLF, sizeof(STR_CRLF) - 1, 0)
		!= (sizeof(STR_CRLF) - 1))
		return (perror_retint("send-err(HTTP Response - sep)", false));
	if (send(sockfd, response_body, body_len, 0) != (ssize_t)body_len)
		return (perror_retint("send-err(HTTP Response - body)", false));
	return (true);
}
