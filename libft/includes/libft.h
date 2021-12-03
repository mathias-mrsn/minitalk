#ifndef LIBFT_H
#define LIBFT_H

#include <stddef.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include "ft_printf.h"
#include "get_next_line.h"

#define INT_MIN -2147483648
#define INT_MAX 2147483647

#define hexa "0123456789abcdef"
#define HEXA "0123456789ABCDEF"

int ft_len(long nb);
long	ft_abs(long x);
char *ft_itoa(int n);
int ft_isalnum(int c);
int ft_isalpha(int c);
int ft_isascii(int c);
int ft_isdigit(int c);
int ft_isprint(int c);
void ft_putnbr(int n);
int ft_tolower(int c);
int ft_toupper(int c);
int	ft_min(int x, int y);
int	ft_max(int x, int y);
void ft_putchar(char c);
void ft_putendl(char *s);
int is_c(char s, char c);
void ft_putstr(char *str);
void ft_putaddr(void *addr);
int ft_atoi(const char *str);
void ft_putnbr_fd(int n, int fd);
char *ft_strdup(const char *src);
size_t ft_strlen(const char *str);
void ft_bzero(void *b, size_t len);
void ft_putchar_fd(char c, int fd);
void ft_putstr_fd(char *s, int fd);
void ft_putendl_fd(char *s, int fd);
int ft_is_charset(char c, char *set);
char *ft_strchr(const char *s, int c);
char *ft_strrchr(const char *s, int c);
void ft_putaddr_fd(void *addr, int fd);
void ft_putnstr(char *str, size_t len);
void ft_fill(long *nb, int n, int *neg);
char **ft_split(char const *str, char c);
int ft_word_len(const char *str, char c);
int ft_count_word(const char *str, char c);
void *ft_calloc(size_t count, size_t size);
void *ft_memset(void *b, int c, size_t len);
char *ft_strcat(const char *s1, const char *s2);
void *ft_memchr(const void *s, int c, size_t n);
char *ft_strjoin(char const *s1, char const *s2);
char *ft_strtrim(const char *s1, const char *set);
void ft_putnstr_fd(char *str, int fd, size_t len);
void *ft_memcpy(void *dst, const void *src, size_t n);
int ft_memcmp(const void *s1, const void *s2, size_t n);
int ft_strncmp(const char *s1, const char *s2, size_t n);
void *ft_memmove(void *dst, const void *src, size_t len);
void	ft_striteri(char *s, void (*f)(unsigned int, char*));
size_t ft_strlcat(char *dest, const char *src, size_t size);
size_t ft_strlcpy(char *dest, const char *src, size_t size);
void *ft_memccpy(void *dst, const void *src, int c, size_t n);
char *ft_strmapi(char const *s, char (*f)(unsigned int, char));
char *ft_substr(char const *s, unsigned int start, size_t len);
char *ft_strnstr(const char *haystack, const char *needle, size_t len);
int		ft_printf(const char *str, ...);

typedef struct s_list
{
	void *content;
	struct s_list *next;
} t_list;

int ft_lstsize(t_list *lst);
t_list *ft_lstlast(t_list *lst);
t_list *ft_lstnew(void *content);
void ft_lstadd_back(t_list **alst, t_list *new);
void ft_lstiter(t_list *lst, void (*f)(void *));
void ft_lstadd_front(t_list **alst, t_list *new);
void ft_lstdelone(t_list *lst, void (*del)(void *));
void ft_lstclear(t_list **lst, void (*del)(void *));
t_list *ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *));

#endif