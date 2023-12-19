/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_req.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 01:21:15 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/19 20:00:04 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// - free
#include <stdlib.h>

#include <libft.h>

#include <ft_httpserv.h>
#include "_res_err.h"

static void	_str_trim(char **str)
{
	size_t	i;
	size_t	len;

	i = 0;
	while (ft_isspace((*str)[i]))
		(*str)[i++] = '\0';
	*str += i;
	len = ft_strlen(*str);
	i = len - 1;
	while (0 < i && ft_isspace((*str)[i]))
		(*str)[i--] = '\0';
	while (ft_isspace((*str)[len - 1]))
		--len;
}

static t_http_header_list	*_read_parse_header(int sockfd, t_gnl_state *state)
{
	t_http_header_list	*headers;
	char				*line;
	char				*value;

	headers = NULL;
	while (true)
	{
		line = get_next_line(state);
		if (line == NULL)
			break ;
		if (ft_isspace_str(line))
			return (headers);
		value = ft_strchr(line, ':');
		if (value == NULL)
			break ;
		*value++ = '\0';
		_str_trim(&value);
		if (!http_header_list_add(&headers, line, value))
			break ;
		free(line);
	}
	free(line);
	http_header_list_free(&headers);
	_res_err_500(sockfd, "error @ " __FILE__);
	return (NULL);
}

static bool	_pick_http_version(t_httpreq *req, const char *path_top)
{
	size_t		i;
	const char	*http_ver_end;

	i = ft_strlen(path_top) - 1;
	while (ft_isspace(path_top[i]))
		--i;
	http_ver_end = path_top + i + 1;
	while (0 < i && path_top[i] != ' ')
		--i;
	if (i == 0)
		return (_res_err_400(req->fd, "start line HTTP version seg not found"));
	req->version = ft_strndup(path_top + i + 1,
			http_ver_end - (path_top + i + 1));
	while (path_top[i] == ' ')
		--i;
	req->path = ft_strndup(path_top, i + 1);
	return (true);
}

static bool	_parse_req_line(t_httpreq *req, const char *line)
{
	size_t		i;

	while (*line == ' ')
		++line;
	i = 0;
	while (line[i] != ' ' && line[i] != '\0')
		i++;
	if (line[i] == '\0')
		return (_res_err_400(req->fd, "start line SPC char not found"));
	req->method = ft_strndup(line, i);
	while (line[i] == ' ')
		i++;
	if (line[i] == '\0')
		return (_res_err_400(req->fd, "start line req target elem not found"));
	if (!_pick_http_version(req, line + i))
		return (false);
	if (req->method == NULL || req->path == NULL || req->version == NULL)
		return (_res_err_500(req->fd, "malloc error @ " __FILE__));
	return (true);
}

// TODO: Request Bodyのサポート
__attribute__((nonnull))
bool	ft_httpserv_parse_req(
	int fd,
	t_httpreq *req
)
{
	t_gnl_state	state;
	char		*line;

	ft_bzero(req, sizeof(t_httpreq));
	state = gen_gnl_state(fd, 4096);
	req->fd = fd;
	if (state.buf == NULL)
		return (_res_err_500(fd, "malloc error @ " __FILE__));
	line = get_next_line(&state);
	if (_parse_req_line(req, line))
	{
		req->header_list = _read_parse_header(fd, &state);
	}
	dispose_gnl_state(&state);
	return (req->header_list != NULL && req->method != NULL
		&& req->path != NULL && req->version != NULL);
}
