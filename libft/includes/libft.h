/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: qstemper <qstemper@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2015/11/09 09:44:51 by qstemper          #+#    #+#             */
/*   Updated: 2017/04/17 12:37:13 by qstemper         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H

# define LIBFT_H

# include <stdlib.h>
# include <stdio.h>
# include <unistd.h>
# include <string.h>
# include <limits.h>

# define MAX_UINT 4294967295

typedef unsigned int		t_uint;
typedef unsigned char		t_uchar;
typedef unsigned long int	t_ulong;
typedef unsigned short int	t_ushort;

typedef struct				s_list
{
	void					*content;
	size_t					content_size;
	struct s_list			*next;
}							t_list;

typedef struct				s_dlist
{
	void					*content;
	size_t					content_size;
	struct s_dlist			*p;
	struct s_dlist			*n;
}							t_dlist;

void						*ft_memset(void *s, int c, size_t length);
void						ft_bzero(void *s, size_t n);
void						*ft_memcpy(void *dest, const void *src, size_t n);
void						*ft_memccpy(void *dest, const void *src, \
								int c, size_t n);
void						*ft_memmove(void *dest, const void *src, \
								size_t length);
void						*ft_memchr(const void *s, int c, size_t n);
int							ft_memcmp(const void *s1, const void *s2, size_t n);
size_t						ft_strlen (const char *s);
char						*ft_strdup(const char *s);
char						*ft_strndup(const char *s, size_t n);
char						*ft_strcpy(char *dest, const char *src);
char						*ft_strncpy(char *dest, const char *src, size_t n);
char						*ft_strcat(char *s1, const char *s2);
char						*ft_strncat(char *s1, const char *s2, size_t n);
size_t						ft_strlcat(char *dest, const char *src, \
								size_t size);
char						*ft_strchr(const char *s, int c);
char						*ft_strrchr(const char *s, int c);
char						*ft_strstr(const char *s1, const char *s2);
char						*ft_strnstr(const char *s1, const char *s2, \
								size_t n);
int							ft_strcmp(const char *s1, const char *s2);
int							ft_strncmp(const char *s1, const char *s2, \
								size_t n);
int							ft_atoi(const char *str);
int							ft_isalpha(int c);
int							ft_isdigit(int c);
int							ft_isalnum(int c);
int							ft_isascii(int c);
int							ft_isprint(int c);
int							ft_isupper(int c);
int							ft_islower(int c);
int							ft_isblank(char c);
int							ft_toupper(int c);
int							ft_tolower(int c);
void						*ft_memalloc(size_t size);
void						ft_memdel(void **ap);
char						*ft_strnew(size_t size);
void						ft_strdel(char **as);
void						ft_strclr(char *s);
void						ft_striter(char *s, void (*f)(char *));
void						ft_striteri(char *s, \
								void (*f)(unsigned int, char *));
char						*ft_strmap(char const *s, char (*f)(char));
char						*ft_strmapi(char const *s, \
								char (*f)(unsigned int, char));
int							ft_strequ(char const *s1, char const *s2);
int							ft_strnequ(char const *s1, \
								char const *s2, size_t n);
char						*ft_strsub(char const *s, \
								unsigned int start, size_t len);
char						*ft_strjoin(char const *s1, char const *s2);
char						*ft_strtrim(char const *s);
char						**ft_strsplit(char const *s, char c);
int							*ft_strsplittoint(char const *s, char c);
char						*ft_itoa(int n);
void						ft_putchar(char c);
void						ft_putstr(char const *s);
void						ft_putendl(char const *s);
void						ft_putnbr(int n);
void						ft_putchar_fd (char c, int fd);
void						ft_putstr_fd(char const *s, int fd);
void						ft_putendl_fd(char const *s, int fd);
void						ft_putnbr_fd(int n, int fd);
t_list						*ft_lstnew(void const *content, \
								size_t content_size);
void						ft_lstdelone(t_list **alst, \
								void (*del)(void *, size_t));
void						ft_lstdel(t_list **alst, \
								void (*del)(void *, size_t));
void						ft_lstadd(t_list **alst, t_list *new);
void						ft_lstiter(t_list *lst, void (*f)(t_list *elem));
t_list						*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
size_t						ft_lstlen(t_list *lst);
void						ft_lstaddback(t_list **alst, t_list *new);
t_list						*ft_lstcpy(t_list *lst);
void						ft_lstaddi(t_list **alst, t_list *new, size_t i);
t_list						*ft_lstreverse(t_list *lst);
t_dlist						*ft_dlstnew(const void *content, \
								size_t content_size);
void						ft_dlstdelone(t_dlist **alst, \
								void(*del)(void *, size_t));
void						ft_dlstdel(t_dlist **alst, \
								void(*del)(void *, size_t));
void						ft_dlstaddp(t_dlist **alst, t_dlist *elem);
void						ft_dlstaddn(t_dlist **alst, t_dlist *elem);
void						ft_dlstaddip(t_dlist **alst, t_dlist *elem, \
								t_uint i);
void						ft_dlstaddip(t_dlist **alst, t_dlist *elem, \
								t_uint i);
t_dlist						*ft_dlstmap(t_dlist *list, t_dlist*(*f)(t_dlist *));
char						*ft_strexp(char *s, size_t size);

#endif
