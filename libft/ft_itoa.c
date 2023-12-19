/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/18 06:34:36 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 19:52:44 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - NULL
// - size_t
#include <stddef.h>

#include "libft.h"

#define NUM_STR_BUF_LEN (12)
#define PNUM_STR_BUF_LEN (22)

static char	*reverse_str(char *str)
{
	char	*str_top;
	char	*str_end;
	char	tmp;

	if (str == NULL)
		return (NULL);
	str_top = str;
	str_end = str;
	while (*str_end != '\0')
		str_end++;
	str_end -= 1;
	while (str_top < str_end)
	{
		tmp = *str_end;
		*str_end-- = *str_top;
		*str_top++ = tmp;
	}
	return (str);
}

static long	ft_absl(long v)
{
	if (v >= 0)
		return (v);
	else
		return (v * -1);
}

__attribute__((nonnull(2)))
static char	*_dup_or_copy(char *buf, const char *src)
{
	if (buf == NULL)
		return (ft_strdup(src));
	else
		return (ft_strcpy(buf, src));
}

char	*ft_itoa(
	int n,
	char *buf
)
{
	char	num_str_buf[NUM_STR_BUF_LEN];
	int		buf_pos;
	long	long_n;

	if (n == 0)
		return (_dup_or_copy(buf, "0"));
	buf_pos = 0;
	long_n = ft_absl(n);
	while (long_n != 0)
	{
		num_str_buf[buf_pos++] = (long_n % 10) + '0';
		long_n /= 10;
	}
	if (n < 0)
		num_str_buf[buf_pos++] = '-';
	num_str_buf[buf_pos] = '\0';
	return (reverse_str(_dup_or_copy(buf, num_str_buf)));
}

char	*ft_ptoa(
	size_t n,
	char *buf
)
{
	char	num_str_buf[PNUM_STR_BUF_LEN];
	int		buf_pos;

	if (n == 0)
		return (_dup_or_copy(buf, "0"));
	buf_pos = 0;
	while (n != 0)
	{
		num_str_buf[buf_pos++] = (n % 10) + '0';
		n /= 10;
	}
	num_str_buf[buf_pos] = '\0';
	return (reverse_str(_dup_or_copy(buf, num_str_buf)));
}
