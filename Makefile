# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/12/16 21:43:29 by kfujita           #+#    #+#              #
#    Updated: 2023/12/17 23:54:52 by kfujita          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME := ft_httpserv

SRCS_MAIN	:= main.c

SRCS_LIBFT	:=\
	can_add.c\
	can_mul.c\
\
	ft_atop.c\
	ft_bzero.c\
	ft_calloc.c\
	ft_isalnum.c\
	ft_isalpha.c\
	ft_isdigit.c\
	ft_islower.c\
	ft_isspace.c\
	ft_isupper.c\
	ft_max.c\
	ft_memchr.c\
	ft_memcpy.c\
	ft_memmove.c\
	ft_memset.c\
	ft_min.c\
\
	get_next_line.c\
\
	vect_append_range.c\
	vect_at.c\
	vect_dispose.c\
	vect_init.c\
	vect_push_back.c\
	vect_remove.c\
	vect_reserve.c\
	vect_set.c\


SRCS_COMMON	:=\
	ft_httpserv.c\

SRCS_BASE_DIR	:= srcs
LIBFT_DIR	:= libft

SRCS_NOMAIN	:=\
	$(addprefix common/, $(SRCS_COMMON))\

HEADERS_DIR	:= headers

OBJS_DIR	:=	./objs
OBJS_LIBFT_DIR	:=	./objs
OBJS_NOMAIN	:=	$(addprefix $(OBJS_DIR)/, $(SRCS_NOMAIN:.c=.o))
OBJS_LIBFT	:=	$(addprefix $(OBJS_LIBFT_DIR)/, $(SRCS_LIBFT:.c=.o))
OBJS_MAIN	:=	$(addprefix $(OBJS_DIR)/, $(SRCS_MAIN:.c=.o))
OBJS	:=	$(OBJS_NOMAIN) $(OBJS_LIBFT) $(OBJS_MAIN)
DEPS	:=	$(addprefix $(OBJS_DIR)/, $(OBJS:.o=.d))

override CFLAGS	+=	-Wall -Wextra -Werror -MMD -MP
INCLUDES	:=\
	-I $(HEADERS_DIR)\
	-I $(LIBFT_DIR)\

all:	$(NAME)

$(NAME):	$(OBJS)
	$(CC) $(CFLAGS) $(INCLUDES) $(OBJS) -o $@

$(OBJS_LIBFT_DIR)/%.o:	$(LIBFT_DIR)/%.c
	@test -d '$(dir $@)' || mkdir -p '$(dir $@)'
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

$(OBJS_DIR)/%.o:	$(SRCS_BASE_DIR)/%.c
	@test -d '$(dir $@)' || mkdir -p '$(dir $@)'
	$(CC) $(CFLAGS) $(INCLUDES) -c -o $@ $<

