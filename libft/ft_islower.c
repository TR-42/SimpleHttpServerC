/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_islower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/04/23 23:03:42 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/17 23:34:27 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - bool
#include <stdbool.h>

#include "libft.h"

bool	ft_islower(int c)
{
	return ('a' <= c && c <= 'z');
}