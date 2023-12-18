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

# define SOCK_BACKLOG 8

typedef struct sockaddr_in	t_sockaddri;
typedef struct sockaddr		t_sockaddr;

typedef struct s_httpserv
{
	uint16_t	port;
	t_sockaddri	serv_addr;
	int			sockfd;
}	t_httpserv;

bool	ft_httpserv_init(
			t_httpserv *serv,
			uint16_t port
			)
		__attribute__((nonnull))
		;

bool	ft_httpserv_loop(
			t_httpserv *serv
			)
		__attribute__((nonnull))
		;

#endif
