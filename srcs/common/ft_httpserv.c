/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_httpserv.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:40:19 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/17 11:05:28 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - bool
#include <stdbool.h>

// - close
#include <unistd.h>

// - shutdown
#include <sys/socket.h>

#include <libft.h>

#include <ft_httpserv.h>
#include <utils.h>

__attribute__((nonnull))
bool	ft_httpserv_init(
	t_httpserv *serv,
	uint16_t port
)
{
	serv->port = port;
	serv->serv_addr.sin_family = AF_INET;
	serv->serv_addr.sin_addr.s_addr = INADDR_ANY;
	serv->serv_addr.sin_port = htons(port);
	serv->sockfd = socket(AF_INET, SOCK_STREAM, IPPROTO_TCP);
	if (serv->sockfd < 0)
		return (perror_retint("socket init", false));
	if (bind(serv->sockfd, (struct sockaddr *)&(serv->serv_addr),
			sizeof(serv->serv_addr)) < 0)
		return (perror_retint("bind", false));
	if (listen(serv->sockfd, 8) < 0)
		return (perror_retint("listen", false));
	return (true);
}

// socket shutdown ref
// -> https://stackoverflow.com/questions/855544/
// 		is-there-a-way-to-flush-a-posix-socket

__attribute__((nonnull))
bool	ft_httpserv_loop(
	t_httpserv *serv
)
{
	int			sockfd;
	t_sockaddr	addr;
	socklen_t	addrlen;
	char		buf[INET6_ADDRSTRLEN + 1];

	while (true)
	{
		ft_bzero(&addr, sizeof(addr));
		addrlen = sizeof(addr);
		sockfd = accept(serv->sockfd, &addr, &addrlen);
		if (sockfd < 0)
			return (perror_retint("accept", false));
		ft_bzero(buf, sizeof(buf));
		get_ipaddr_str(&addr, buf);
		errstr_retint("accepted connection from", buf, 0);
		ft_httpserv_process_req(sockfd);
		shutdown(sockfd, SHUT_RDWR);
		close(sockfd);
	}
	return (true);
}
