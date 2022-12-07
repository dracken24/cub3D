/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nadesjar <dracken24@gmail.com>             +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/03/30 14:00:19 by nadesjar          #+#    #+#             */
/*   Updated: 2022/07/29 12:03:01 by nadesjar         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stddef.h>
# include <string.h>
# include <unistd.h>
# include <stdlib.h>
# include <ctype.h>
# include <stdio.h>
# include <stdbool.h>

# define INT_MIN -2147483648
# define INT_MAX 2147483647

typedef struct s_list
{
	void			*content;
	struct s_list	*next;
}					t_list;

size_t		ft_strlcat(char *dest, char *src, size_t size);
size_t		ft_strlcpy(char *dest, char *src, size_t size);
size_t		ft_strlen(const char *str);

t_list		*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));
t_list		*ft_lstnew(void *content);
t_list		*ft_lstlast(t_list *lst);

long int	ft_atoi(const char *str);
int			ft_memcmp(const void *s1, const void *s2, size_t len);
int			ft_strncmp(char *s1, char *s2, size_t n);
int			ft_atoi_base(char *str, char *base);
int			ft_array_len(int *nbrs);
int			ft_lstsize(t_list *lst);
int			ft_p_or_imp(int nbr);
int			ft_isdigit(int c);
int			ft_isalnum(int c);
int			ft_isalpha(int c);
int			ft_isascii(int c);
int			ft_isprint(int c);
int			ft_toupper(int c);
int			ft_tolower(int c);

bool		ft_strchr_bool(const char *str, int c);

char		*ft_strnstr(const char *str, const char *to_find, size_t len);
char		*ft_strmapi(const char *str, char (*f)(unsigned int, char));
char		*ft_substr(char const *s, unsigned int start, size_t len);
char		*ft_strtrim(char const *s1, char const *set);
char		*ft_strjoin(char const *s1, char const *s2);
char		*ft_strrchr(const char *str, int c);
char		*ft_strchr(const char *str, int c);
char		**ft_split(char const *s, char c);
char		*ft_strdup(char *src);
char		*ft_itoa(int n);

void		ft_striteri(char *str, void (*f)(unsigned int, char *));
void		*ft_memmove(void *dest, const void *src, size_t len);
void		*ft_memcpy(void *dest, const void *src, size_t len);
void		ft_lstdelone(t_list *lst, void (*del)(void *));
void		ft_lstclear(t_list **lst, void (*del)(void *));
void		*ft_memchr(const void *src, int c, size_t len);
void		ft_lstadd_front(t_list **lst, t_list *new);
void		ft_lstadd_back(t_list **lst, t_list *new);
void		ft_lstiter(t_list *lst, void (*f)(void *));
void		*ft_memset(void *str, int c, size_t len);
void		*ft_calloc(size_t count, size_t size);
void		ft_bzero(void *str, size_t len);
void		ft_putendl_fd(char *str, int fd);
void		ft_putstr_fd(char *str, int fd);
void		ft_putchar_fd(char c, int fd);
void		ft_putnbr_fd(int nb, int fd);
void		ft_swap(int *a, int *b);
void		free_ptr(char **tab);

#endif
