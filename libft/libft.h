/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kfujita <kfujita@student.42tokyo.jp>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/16 21:42:40 by kfujita           #+#    #+#             */
/*   Updated: 2023/12/18 00:02:33 by kfujita          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

// - size_t
# include <stddef.h>

// - bool
# include <stdbool.h>

// - ssize_t
# include <sys/types.h>

# define CHAR_HTAB '\t'
# define CHAR_LF '\n'
# define CHAR_VTAB '\v'
# define CHAR_FF '\f'
# define CHAR_CR '\r'
# define CHAR_WS ' '

# ifndef FT_VECT_EXPAND_STEP
#  define FT_VECT_EXPAND_STEP 32
# endif

/**
 * @brief Check if `a + b` can be executed successfully
 * 
 * @param a value1
 * @param b value2
 * @return can be executed successfully(`true`) or not(`false`)
 */
bool		can_add(int a, int b);
/**
 * @brief Check if `a + b` can be executed successfully
 * 
 * @param a value1
 * @param b value2
 * @return can be executed successfully(`true`) or not(`false`)
 */
bool		can_addu(unsigned int a, unsigned int b);
/**
 * @brief Check if `a + b` can be executed successfully
 * 
 * @param a value1
 * @param b value2
 * @return can be executed successfully(`true`) or not(`false`)
 */
bool		can_addl(long a, long b);
/**
 * @brief Check if `a + b` can be executed successfully
 * 
 * @param a value1
 * @param b value2
 * @return can be executed successfully(`true`) or not(`false`)
 */
bool		can_addp(size_t a, size_t b);

/**
 * @brief Check if `a * b` can be executed successfully
 * 
 * @param a value1
 * @param b value2
 * @return can be executed successfully(`true`) or not(`false`)
 */
bool		can_mul(int a, int b);
/**
 * @brief Check if `a * b` can be executed successfully
 * 
 * @param a value1
 * @param b value2
 * @return can be executed successfully(`true`) or not(`false`)
 */
bool		can_mulu(unsigned int a, unsigned int b);
/**
 * @brief Check if `a * b` can be executed successfully
 * 
 * @param a value1
 * @param b value2
 * @return can be executed successfully(`true`) or not(`false`)
 */
bool		can_mull(long a, long b);
/**
 * @brief Check if `a * b` can be executed successfully
 * 
 * @param a value1
 * @param b value2
 * @return can be executed successfully(`true`) or not(`false`)
 */
bool		can_mulp(size_t a, size_t b);

/**
 * @brief free 2d array `ptr` and set `NULL` to `ptr`
 * 
 * @param ptr 2d array pointer address to free
 */
void		free2d(
				void ***ptr
				)
			;

/**
 * @brief convert `str` to `size_t` with `base` and `max`
 * 
 * @param str string to convert
 * @param endptr pointer to the last character
 * @param base base of `str`
 * @param max max value of `str`
 * @return converted value
 */
size_t		ft_atop(
				const char *str,
				const char **endptr,
				unsigned char base,
				size_t max
				)
			__attribute__((nonnull(1)))
			;

/**
 * @brief set `0` to `*s` for `n` bytes
 * 
 * @param s destination
 * @param n bytes to set
 */
void		ft_bzero(
				void *s,
				size_t n
				)
			;

/**
 * @brief Allocate memory for `count` elements of `size` bytes each
 * 		(it does not set `0` to the allocated memory)
 * 
 * @param count number of elements
 * @param size size of each element [bytes]
 * @return allocated memory or `NULL` if allocation fails
 */
void		*ft_calloc_nofill(
				size_t count,
				size_t size
				)
			;
/**
 * @brief Allocate memory for `count` elements of `size` bytes each
 * 		and set `0` to the allocated memory
 * 
 * @param count number of elements
 * @param size size of each element [bytes]
 * @return allocated memory or `NULL` if allocation fails
 */
void		*ft_calloc(
				size_t count,
				size_t size
				)
			;
/**
 * @brief Allocate memory for `count` elements of `size` bytes each
 * 		then move `src` to the allocated memory for `src_bytes` and free `src`
 * 
 * @param src source
 * @param src_bytes bytes to move from `src`
 * @param count number of elements
 * @param size size of each element [bytes]
 * @return allocated memory or `NULL` if allocation fails
 */
void		*ft_calloc_move(
				void **src,
				size_t src_bytes,
				size_t count,
				size_t size
				)
			;

/**
 * @brief get is `c` is a alphanumerical character or not
 * 
 * @param c character
 * @return is alphanumerical character or not
 */
bool		ft_isalnum(
				int c
				)
			;
/**
 * @brief get is `c` is a alphabetical character or not
 * 
 * @param c character
 * @return is alphabetical character or not
 */
bool		ft_isalpha(
				int c
				)
			;
/**
 * @brief get is `c` is a digit character or not
 * 
 * @param c character
 * @return is digit character or not
 */
bool		ft_isdigit(
				int c
				)
			;
/**
 * @brief get is `c` is a lower character or not
 * 
 * @param c character
 * @return is lower character or not
 */
bool		ft_islower(
				int c
				)
			;
/**
 * @brief get is `c` is a space character or not
 * 
 * @param c character
 * @return is space character or not
 */
bool		ft_isspace(
				int c
				)
			;
/**
 * @brief get is `c` is a space or `\0` character, or not
 * 
 * @param c character
 * @return is space character or not
 */
bool		ft_isspcornil(
				int c
				)
			;
/**
 * @brief get is `c` is a upper character or not
 * 
 * @param c character
 * @return is upper character or not
 */
bool		ft_isupper(
				int c
				)
			;

/**
 * @brief get bigger value
 * 
 * @param a value1
 * @param b value2
 * @return bigger value
 */
int			ft_max(int a, int b);
/**
 * @brief get bigger value
 * 
 * @param a value1
 * @param b value2
 * @return bigger value
 */
long		ft_maxl(long a, long b);
/**
 * @brief get bigger value
 * 
 * @param a value1
 * @param b value2
 * @return bigger value
 */
size_t		ft_maxp(size_t a, size_t b);
/**
 * @brief get bigger value
 * 
 * @param a value1
 * @param b value2
 * @return bigger value
 */
double		ft_maxf(double a, double b);

/**
 * @brief get pointer to the first occurrence of `c` in `s` in `n` bytes
 * 
 * @param s source
 * @param c value to find (as `unsigned char`)
 * @param n bytes to search
 * @return pointer to the first occurrence of `c` in `s` in `n` bytes
 * 		or `NULL` if not found
 */
void		*ft_memchr(
				const void *s,
				int c,
				size_t n
				)
			;
/**
 * @brief copy `n` bytes from `src` to `dst`
 * 
 * @param dst destination
 * @param src source
 * @param n bytes to copy
 * @return `dst`
 */
void		*ft_memcpy(
				void *dst,
				const void *src,
				size_t n
				)
			;
/**
 * @brief copy `n` bytes from `src` to `dst`
 * 
 * @param dst destination
 * @param src source
 * @param n bytes to copy
 * @return `dst`
 */
void		*ft_memmove(
				void *dst,
				const void *src,
				size_t n
				)
			;
/**
 * @brief set `c` to `b` for `n` bytes
 * 
 * @param b destination
 * @param c value to set
 * @param len bytes to set
 * @return `b`
 */
void		*ft_memset(
				void *b,
				int c,
				size_t len
				)
			;

/**
 * @brief get smaller value
 * 
 * @param a value1
 * @param b value2
 * @return smaller value
 */
int			ft_min(int a, int b);
/**
 * @brief get smaller value
 * 
 * @param a value1
 * @param b value2
 * @return smaller value
 */
long		ft_minl(long a, long b);
/**
 * @brief get smaller value
 * 
 * @param a value1
 * @param b value2
 * @return smaller value
 */
size_t		ft_minp(size_t a, size_t b);
/**
 * @brief get smaller value
 * 
 * @param a value1
 * @param b value2
 * @return smaller value
 */
double		ft_minf(double a, double b);

/**
 * @brief check whether `a` and `b` are equal or not
 * 
 * @param a value1
 * @param b value2
 * @return `a` and `b` are equal(`0`) or not
 */
int			ft_strcmp(
				const char *a,
				const char *b
				)
			;
/**
 * @brief duplicate `s` to newly allocated memory
 * 
 * @param s1 source
 * @return duplicated string or `NULL` if allocation fails
 */
char		*ft_strdup(
				const char *s1
				)
			;

/**
 * @brief get length of `str`
 * 
 * @param str string
 * @return length of `str`
 */
size_t		ft_strlen(
				const char *str
				)
			;

// #pragma region GetNextLine

/**
 * @brief GetNextLine state
 * 
 * @param fd File descriptor
 * @param buf Buffer ptr
 * @param len Buffer length
 * @param cap Buffer capacity
 */
typedef struct s_gnl_state
{
	int		fd;
	char	*buf;
	ssize_t	len;
	ssize_t	cap;
}	t_gnl_state;

/**
 * @brief initialize GetNextLine state
 * 
 * @param fd fd to read from
 * @param cap read buffer capacity
 * @return initialized state
 */
t_gnl_state	gen_gnl_state(
				int fd,
				ssize_t cap
				)
			;

/**
 * @brief free GetNextLine state
 * 
 * @param state state to free
 */
void		dispose_gnl_state(
				t_gnl_state *state
				)
			__attribute__((nonnull))
			;

/**
 * @brief Get the next line object
 * 
 * @param state GNL state object
 * @return next line or `NULL` if EOF
 */
char		*get_next_line(
				t_gnl_state *state
				)
			;
// #pragma endregion GetNextLine

// #pragma region vect
typedef struct s_vect
{
	size_t	cap;
	size_t	len;
	size_t	elemsize;
	void	*p;
}	t_vect;

bool		vect_append_str(
				t_vect *vect,
				const char *value,
				size_t count
				)
			__attribute__((nonnull))
			;
bool		vect_append_range(
				t_vect *vect,
				const void *value,
				size_t count
				)
			__attribute__((nonnull))
			;

void		*vect_at(
				const t_vect *vect,
				size_t index
				)
			__attribute__((nonnull))
			;

void		vect_dispose(
				t_vect *vect
				)
			__attribute__((nonnull))
			;
void		vect_dispose_each(
				t_vect *vect,
				void (*disposer)(void *)
				)
			__attribute__((nonnull(1)))
			;
void		vect_dispose_ptrarr(
				t_vect *vect
				)
			__attribute__((nonnull))
			;

t_vect		vect_init(
				size_t cap,
				size_t elemsize
				)
			;

bool		vect_push_back(
				t_vect *vect,
				const void *elem,
				size_t *written_index
				)
			__attribute__((nonnull(1, 2)))
			;

bool		vect_remove(
				t_vect *vect,
				size_t index
				)
			__attribute__((nonnull))
			;

bool		vect_reserve(
				t_vect *vect,
				size_t newcap
				)
			__attribute__((nonnull))
			;

bool		vect_set(
				t_vect *vect,
				const void *elem,
				size_t index
				)
			__attribute__((nonnull))
			;
// #pragma endregion vect

#endif
