/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/06 18:17:29 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/17 23:57:05 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - read
#include <unistd.h>

// - ssize_t
#include <sys/types.h>

// - free
#include <stdlib.h>

#include "libft.h"

t_gnl_state	gen_gnl_state(
	int fd,
	ssize_t cap
)
{
	t_gnl_state	state;

	ft_bzero(&state, sizeof(t_gnl_state));
	state.buf = ft_calloc(cap, sizeof(char));
	if (state.buf != NULL)
		state.cap = cap;
	state.fd = fd;
	return (state);
}

void	dispose_gnl_state(
	t_gnl_state *state
)
{
	free(state->buf);
	ft_bzero(state, sizeof(t_gnl_state));
}

// `\n` found: TRUE
//  not found: FALSE
__attribute__((nonnull))
static bool	check_and_update_state(
	t_vect *ret,
	t_gnl_state *state
)
{
	char	*lf_ptr;
	size_t	append_len;

	if (state->len == 0)
		return (false);
	lf_ptr = (char *)ft_memchr(state->buf, '\n', state->len);
	if (lf_ptr == NULL)
		append_len = state->len;
	else
		append_len = lf_ptr - state->buf + 1;
	vect_append_str(ret, state->buf, append_len);
	if (lf_ptr != NULL)
	{
		ft_memmove(state->buf, state->buf + append_len,
			state->len - append_len);
		state->len -= append_len;
	}
	else
		state->len = 0;
	return (lf_ptr != NULL);
}

char	*get_next_line(t_gnl_state *state)
{
	t_vect	ret;
	ssize_t	read_result;

	if (state == NULL || state->buf == NULL || state->cap == 0)
		return (NULL);
	ret = vect_init(0, sizeof(char));
	if (check_and_update_state(&ret, state))
		return (ret.p);
	while (true)
	{
		read_result = read(state->fd, state->buf, state->cap);
		if (read_result <= 0)
		{
			dispose_gnl_state(state);
			if (ret.len == 0)
				vect_dispose(&ret);
			return (ret.p);
		}
		state->len = read_result;
		if (check_and_update_state(&ret, state))
			return (ret.p);
	}
}
