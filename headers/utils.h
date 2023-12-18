/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:39:21 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 01:12:21 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

// - sockaddr
# include <arpa/inet.h>

// - size_t
# include <stddef.h>

size_t	get_ipaddr_str(
			const struct sockaddr *addr,
			char *buf
			)
		__attribute__((nonnull))
		;

#endif
