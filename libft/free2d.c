/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free2d.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/18 00:29:07 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/18 00:33:44 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - free
// - NULL
#include <stdlib.h>

static void	_free2d(void **ptr)
{
	void	**ptr_top;

	if (ptr == NULL)
		return ;
	ptr_top = ptr;
	while (*ptr != NULL)
		free(*ptr++);
	free(ptr_top);
}

void	free2d(
	void ***ptr
)
{
	if (ptr == NULL || *ptr == NULL)
		return ;
	_free2d(*ptr);
	*ptr = NULL;
}
