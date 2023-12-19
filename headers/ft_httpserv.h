/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_httpserv.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:42:51 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/16 21:42:57 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_HTTPSERV_H
# define FT_HTTPSERV_H

// - bool
// - uint16_t
# include <stdbool.h>

// - struct sockaddr_in
# include <arpa/inet.h>

# include <http_header_list.h>

# define SOCK_BACKLOG 8

# define STR_CRLF "\r\n"

typedef struct sockaddr_in	t_sockaddri;
typedef struct sockaddr		t_sockaddr;

typedef struct s_httpserv
{
	uint16_t	port;
	t_sockaddri	serv_addr;
	int			sockfd;
}	t_httpserv;

typedef struct s_httpreq
{
	int					fd;
	t_sockaddr			addr;
	char				*method;
	char				*path;
	char				*version;
	t_http_header_list	*header_list;
	uint8_t				*body;
	size_t				body_size;
}	t_httpreq;

typedef struct s_httpres
{
	int					fd;
	uint16_t			status_code;
	const char			*reason_phrase;
	t_http_header_list	*header_list;
	uint8_t				*body;
	size_t				body_size;
}	t_httpres;

typedef enum e_http_status_code
{
	HTTP_STATUS_OK = 200,
	HTTP_STATUS_BAD_REQUEST = 400,
	HTTP_STATUS_NOT_FOUND = 404,
	HTTP_STATUS_INTERNAL_SERVER_ERROR = 500,
}	t_http_status_code;

bool		ft_httpserv_init(
				t_httpserv *serv,
				uint16_t port
				)
			__attribute__((nonnull))
			;

bool		ft_httpserv_loop(
				t_httpserv *serv
				)
			__attribute__((nonnull))
			;

void		ft_httpserv_dispose_httpreq(
				t_httpreq *req
				)
			__attribute__((nonnull))
			;

const char	*get_http_status_msg(
				t_http_status_code status_code
				)
			;

bool		ft_httpserv_parse_req(
				int fd,
				t_httpreq *req
				)
			__attribute__((nonnull))
			;

bool		ft_httpserv_process_req(
				int fd
				)
			;

bool		ft_httpserv_send_simple_res(
				int sockfd,
				t_http_status_code status_code,
				const char *response_body
				)
			;

bool		ft_httpserv_send_status(
				int sockfd,
				t_http_status_code status_code
				)
			;
bool		ft_httpserv_send_header(
				int sockfd,
				const char *key,
				const char *value
				)
			__attribute__((nonnull))
			;

#endif
