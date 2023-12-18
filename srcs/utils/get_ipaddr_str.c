/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_ipaddr_str.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 00:39:34 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 01:18:20 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - sockaddr_in
// - sockaddr_in6
#include <arpa/inet.h>

// - NULL
// - size_t
#include <stddef.h>

#include <stdio.h>

#include <utils.h>

__attribute__((nonnull))
static size_t	_set_value_str(
	char *dst,
	uint16_t value,
	uint8_t base
)
{
	size_t		i;
	uint16_t	tmp;

	if (value < base)
	{
		if (value < 10)
			dst[0] = '0' + value;
		else
			dst[0] = 'a' + value - 10;
		return (1);
	}
	i = _set_value_str(dst, value / base, base);
	tmp = value % base;
	if (tmp < 10)
		dst[i] = '0' + tmp;
	else
		dst[i] = 'a' + tmp - 10;
	return (i + 1);
}

static size_t	_ipv6_addr(
	const struct in6_addr *addr,
	char *buf
)
{
	size_t	i;
	size_t	len;

	i = 0;
	len = 0;
	while (i < 8)
	{
		len += _set_value_str(buf + len,
				ntohs(addr->__u6_addr.__u6_addr16[i]), 16);
		if (i != 7)
			buf[len++] = ':';
		i++;
	}
	return (len);
}

static size_t	_ipv4_addr(
	const struct in_addr *addr,
	char *buf
)
{
	size_t	i;
	size_t	len;
	uint8_t	tmp;

	i = 0;
	len = 0;
	while (i < 4)
	{
		tmp = addr->s_addr >> (i * 8);
		len += _set_value_str(buf + len, tmp, 10);
		if (i != 3)
			buf[len++] = '.';
		i++;
	}
	return (len);
}

__attribute__((nonnull))
size_t	get_ipaddr_str(
	const struct sockaddr *addr,
	char *buf
)
{
	if (addr->sa_family == AF_INET)
		return (_ipv4_addr(&(((struct sockaddr_in *)addr)->sin_addr), buf));
	else if (addr->sa_family == AF_INET6)
		return (_ipv6_addr(&(((struct sockaddr_in6 *)addr)->sin6_addr), buf));
	else
		return (0);
}
