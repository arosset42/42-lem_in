/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kahantar <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/01/19 11:02:29 by kahantar          #+#    #+#             */
/*   Updated: 2017/05/11 15:23:59 by kahantar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <unistd.h>
# include <string.h>
# include <stdlib.h>
# define BUFF_SIZE 1

typedef struct		s_list
{
	void			*content;
	size_t			content_size;
	struct s_list	*next;
}					t_list;

char				*ft_strdup(const char *src);
int					ft_putendlreturn(char const *s);
size_t				ft_strlen(const char *str);
long int			ft_atoi(const char *str);
char				*ft_strcpy(char *dest, const char *src);
char				*ft_strncpy(char *dest, const char *src, size_t n);
char				*ft_strstr(char *str, const char *to_find);
int					ft_strcmp(const char *s1, const char *s2);
int					ft_strncmp(char *s1, char *s2, size_t n);
char				*ft_strcat(char *dest, const char *src);
char				*ft_strncat(char *dest, char *src, size_t nb);
int					ft_isdigit(int c);
int					ft_isalpha(int c);
int					ft_isalnum(int c);
int					ft_tolower(int c);
int					ft_toupper(int c);
int					ft_isprint(int c);
char				*ft_strrchr(char *s, int c);
char				*ft_strchr(const char *s, int c);
void				*ft_memset(void *s, int c, size_t n);
void				ft_bzero(void *s, size_t n);
void				*ft_memcpy(void *dest, const void *src, size_t n);
void				*ft_memccpy(void *dest, const void *src, int c, size_t n);
void				*ft_memchr(const void *s, int c, size_t n);
int					ft_memcmp(const void *s1, const void *s2, size_t n);
void				*ft_memalloc(size_t size);
void				ft_memdel(void **ap);
char				*ft_strnew(size_t size);
void				ft_strdel(char **as);
void				ft_strclr(char *s);
void				ft_striter(char *s, void (*f)(char *));
void				ft_striteri(char *s, void (*f)(unsigned int, char *));
char				*ft_strmap(char const *s, char (*f)(char));
char				*ft_strmapi(char const *s, char (*f)(unsigned int, char));
int					ft_strequ(char const *s1, char const *s2);
char				*ft_strsub(char const *s, unsigned int start, size_t len);
int					ft_strnequ(char const *s1, char const *s2, size_t n);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_strtrim(char const *s);
void				ft_putchar(char c);
char				**ft_strsplit(char const *str, char c);
void				ft_putstr(char const *s);
void				ft_putendl(char const *s);
void				ft_putnbr(int n);
void				ft_putchar_fd(char c, int fd);
void				ft_putendl_fd(char const *s, int fd);
void				ft_putnbr_fd(int n, int fd);
void				ft_putchar_fd(char c, int fd);
void				*ft_memmove(void *dest, const void *src, size_t n);
char				*ft_itoa(int n);
size_t				ft_strlcat(char *dest, char *src, size_t size);
char				*ft_strnstr(char *str, const char *to_find, size_t len);
int					ft_isascii(int c);
void				ft_putstr_fd(char const *s, int fd);
t_list				*ft_lstnew(void const *content, size_t content_size);
void				ft_lstdel(t_list **alst, void (*del)(void*, size_t));
void				ft_lstiter(t_list *lst, void(*f)(t_list *elem));
t_list				*ft_lstmap(t_list *lst, t_list *(*f)(t_list *elem));
void				ft_lstdelone(t_list **alst, void (*del)(void*, size_t));
int					get_next_line(const int fd, char **line);

#endif