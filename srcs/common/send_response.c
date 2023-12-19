/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   send_response.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 19:06:06 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 20:08:40 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - size_t
#include <stddef.h>

// - send
#include <sys/socket.h>

#include <libft.h>

#include <ft_httpserv.h>

#define BUF_SIZE 256

#define HTTP_VER_STR "HTTP/1.0"
#define HTTP_HEADER_SEP ": "

bool	ft_httpserv_send_status(
	int sockfd,
	t_http_status_code status_code
)
{
	char		buf[BUF_SIZE];
	size_t		len;

	buf[0] = '\0';
	len = ft_strlcat(buf, HTTP_VER_STR, BUF_SIZE);
	buf[len++] = ' ';
	ft_itoa(status_code, buf + len);
	ft_strlcat(buf, " ", BUF_SIZE);
	ft_strlcat(buf, get_http_status_msg(status_code), BUF_SIZE);
	ft_strlcat(buf, STR_CRLF, BUF_SIZE);
	len = ft_strlen(buf);
	if (send(sockfd, buf, len, 0) != (ssize_t)len)
		return (perror_retint("send(HTTP Response - status line)", false));
	return (true);
}

__attribute__((nonnull))
bool	ft_httpserv_send_header(
	int sockfd,
	const char *key,
	const char *value
)
{
	size_t	len;
	ssize_t	ret;

	len = ft_strlen(key);
	ret = send(sockfd, key, len, 0);
	if (ret != (ssize_t)len)
		return (perror_retint("send(HTTP Header - key)", false));
	len = sizeof(HTTP_HEADER_SEP) - 1;
	ret = send(sockfd, HTTP_HEADER_SEP, len, 0);
	if (ret != (ssize_t)len)
		return (perror_retint("send(HTTP Header - sep)", false));
	len = ft_strlen(value);
	ret = send(sockfd, value, len, 0);
	if (ret != (ssize_t)len)
		return (perror_retint("send(HTTP Header - val)", false));
	len = sizeof(STR_CRLF) - 1;
	ret = send(sockfd, STR_CRLF, len, 0);
	if (ret != (ssize_t)len)
		return (perror_retint("send(HTTP Header - sep)", false));
	return (true);
}
