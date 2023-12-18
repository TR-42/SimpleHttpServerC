/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_retint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 22:42:03 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 01:03:28 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - errno
#include <errno.h>

// - strerror
#include <string.h>

// - STDERR_FILENO
#include <unistd.h>

#include "libft.h"

int	perror_retint(
	const char *title,
	int ret
)
{
	return (strerr_retint(title, errno, ret));
}

int	strerr_retint(
	const char *title,
	int _errno,
	int ret
)
{
	return (errstr_retint(title, strerror(_errno), ret));
}

int	errstr_retint(
	const char *title,
	const char *errstr,
	int ret
)
{
	ft_putstr_fd(title, STDERR_FILENO);
	if (title != NULL && errstr != NULL)
		ft_putstr_fd(": ", STDERR_FILENO);
	ft_putstr_fd(errstr, STDERR_FILENO);
	ft_putstr_fd("\n", STDERR_FILENO);
	return (ret);
}
