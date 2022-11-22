/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dnieto-c <dnieto-c@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/15 12:51:24 by dnieto-c          #+#    #+#             */
/*   Updated: 2022/11/22 17:08:26 by dnieto-c         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef UTILS_H
# define UTILS_H

# include <stdlib.h>
# include <unistd.h>
# include <fcntl.h>
# include <stdarg.h>
# include <fcntl.h>
# define BUFFER_SIZE 10

typedef struct list
{
	void		*content;
	struct list	*next;
}				t_list;

typedef struct list_tabs
{
	char				**tab;
	struct list_tabs	*next;
}						t_lstb;

int		ft_abs(int a, int b);
void	ft_bzero(void *s, size_t n);
void	*ft_calloc(size_t nmemb, size_t size);
int		ft_isnegative(int n);
void	*ft_memset(void *s, int c, size_t n);
char	*ft_strchr(const char *s, int c);
char	*ft_strjoin_secure(char *s1, char *s2);
int		ft_strlen_int(char *s);
char	**ft_split(char const *str, char c);
char	*ft_strdup(const char *s);
int		ft_atoi(const char *str);
void	ft_swap(int *x, int *y);
/*All prototypes functions of related of linked list of void* */
t_list	*ft_lstnew(void *content);
void	ft_lstadd_back(t_list **lst, t_list *new);
t_list	*ft_lstlast(t_list *lst);
int		ft_free_list(t_list *lst);

/*All prototypes functions of related of linked list of void* */
t_lstb	*ft_lstnew_tab(char *str, char sep);
void	ft_lstadd_back_tab(t_lstb **lst, t_lstb *new);
t_lstb	*ft_lstlast_tab(t_lstb *lst);
int		ft_free_list_tab(t_lstb *lst);
/*
All prototypes functions of ft_printf project.
Directory : ft_printf
*/
int		ft_printf(const char *str, ...);
int		ft_get_format(va_list args, const char format);
int		ft_putchar(int c);
int		ft_putstr(char *str);
int		ft_putnbr(int nbr);
int		ft_puthex(unsigned int hex, char format);
int		ft_len_unsigned(unsigned int n);
char	*ft_uitoa(unsigned int n);
int		ft_put_unsigned(unsigned int n);
int		ft_len_ptr(unsigned long long int_pointer);
void	ft_put_ptr(unsigned long long int_pointer);
int		ft_print_ptr(unsigned long long int_pointer);

/*Functions for get next line*/
char	*get_next_line(int fd);
/*Functions for free*/
void	ft_free_double_tab(char **tab);
#endif