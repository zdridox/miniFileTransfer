/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mzdrodow <mzdrodow@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/10/06 02:05:09 by mzdrodow          #+#    #+#             */
/*   Updated: 2025/11/28 14:07:50 by mzdrodow         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <fcntl.h>
# include <stdarg.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

typedef struct s_list
{
	void				*content;
	struct s_list		*next;
}						t_list;

typedef struct s_gnl_list
{
	int					fd;
	char				*buffer;
	int					bytes_read;
	struct s_gnl_list	*next;
}						t_gnl_list;

void					*ft_memset(void *ptr, unsigned int c, size_t n);
char					**ft_split(char const *s, char c);
void					*ft_calloc(size_t nitems, size_t size);
int						ft_isalnum(char a);
int						ft_isalpha(char a);
int						ft_isdigit(char a);
void					*ft_memchr(void *str, unsigned int c, size_t n);
int						ft_memcmp(const void *p1, const void *p2, size_t n);
void					*ft_memcpy(void *dest, const void *src, size_t n);
char					*ft_strchr(const char *str, int search_char);
char					*ft_strdup(char *src);
size_t					ft_strlcpy(char *dest, const char *src, size_t size);
size_t					ft_strlen(const char *str);
char					*ft_strrchr(const char *s, int search_char);
int						ft_strncmp(const char *s1, const char *s2, size_t n);
int						ft_toupper(int c);
int						ft_tolower(int c);
void					ft_bzero(void *src, size_t n);
void					*ft_memmove(void *dest, const void *src, size_t n);
int						ft_isascii(int c);
int						ft_isprint(int c);
size_t					ft_strlcat(char *dest, const char *src, size_t size);
char					*ft_strnstr(const char *str, const char *to_find,
							size_t len);
int						ft_atoi(const char *str);
char					*ft_substr(char const *s, unsigned int start,
							size_t len);
char					*ft_strjoin(char const *s1, char const *s2);
char					*ft_strtrim(char const *s1, char const *set);
char					*ft_itoa(int n);
char					*ft_strmapi(const char *s, char (*f)(unsigned int,
								char));
void					ft_striteri(char *s, void (*f)(unsigned int, char *));
void					ft_putchar_fd(char c, int fd);
void					ft_putstr_fd(char *s, int fd);
void					ft_putendl_fd(char *s, int fd);
void					ft_putnbr_fd(int n, int fd);
t_list					*ft_lstnew(void *content);
void					ft_lstadd_front(t_list **lst, t_list *new);
int						ft_lstsize(t_list *lst);
t_list					*ft_lstlast(t_list *lst);
void					ft_lstadd_back(t_list **lst, t_list *new);
void					ft_lstdelone(t_list *lst, void (*del)(void *));
void					ft_lstclear(t_list **lst, void (*del)(void *));
void					ft_lstiter(t_list *lst, void (*f)(void *));
t_list					*ft_lstmap(t_list *lst, void *(*f)(void *),
							void (*del)(void *));
int						putnbr(int nbr);
int						putunbr(unsigned int nbr);
int						putstr(char *str);
char					*unsigned_itoa(unsigned int num);
int						ft_printf(const char *str, ...);
char					*int_to_hex(unsigned long num, int type);
int						char_index(char *str, char c);
int						printpointer(void *p);
int						puthex(unsigned long num, int type);

char					*get_next_line(int fd);
int						check_for_newline(char *buff, int size);
void					line_resize(char **line, int size, int new_size);
t_gnl_list				*handle_fd(t_gnl_list **list, int fd);
t_gnl_list				*add_fd_back(t_gnl_list **list, int fd);
void					free_buffer(t_gnl_list **buffers, int fd);
void					grab_data(char **line, t_gnl_list *current_fd,
							int *bytes_total, int fd);
void					load_buffer(char **line, t_gnl_list *current_fd,
							int *bytes_total, int fd);
void					handle_buffer(char **line, t_gnl_list *current_fd,
							int *bytes_total, t_gnl_list **_buffers);
#endif
