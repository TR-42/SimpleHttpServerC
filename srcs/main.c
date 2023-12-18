/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:40:16 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/16 21:43:26 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - EXIT_FAILURE
#include <stdlib.h>

#include <ft_httpserv.h>

int	main(int argc, const char *argv[])
{
	t_httpserv	serv;

	(void)argc;
	(void)argv;
	if (!ft_httpserv_init(&serv, 8080))
		return (EXIT_FAILURE);
	if (!ft_httpserv_loop(&serv))
		return (EXIT_FAILURE);
	return (0);
}
