/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   _res_err.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 23:32:02 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 23:35:41 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef _RES_ERR_H
# define _RES_ERR_H

bool	_res_err_400(int sockfd, const char *msg);
bool	_res_err_500(int sockfd, const char *msg);

#endif
