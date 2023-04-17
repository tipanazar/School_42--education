/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:21:48 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/17 20:04:18 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

int				ft_atoi(char *str);
void			ft_bzero(void *ptr, int num);
void			*ft_calloc(int num, int size);
int				ft_isalnum(int symbol);
int				ft_isalpha(int ch);
int				ft_isascii(int num);
int				ft_isdigit(int num);
int				ft_isprint(int symbol);
void			*ft_memchr(void *s, int c, int n);
int				ft_memcmp(void *s1, void *s2, unsigned int n);
void			*ft_memcpy(void *dest, const void *src, size_t num);
void			*ft_memmove(void *dest, void *src, int num);
void			*ft_memset(void *ptr, int value, int num);
char			*ft_strchr(const char *s, char c);
char			*ft_strdup(const char *str);
unsigned int	ft_strlcat(char *dest, char *src, unsigned int size);
unsigned int	ft_strlcpy(char *dest, char *src, unsigned int size);
size_t			ft_strlen(const char *str);
int				ft_strncmp(const char *s1, const char *s2, size_t n);
char			*ft_strnstr(char *haystack, char *needle, int n);
char			*ft_strrchr(const char *s, int c);
int				ft_tolower(int c);
int				ft_toupper(int c);
char			*ft_substr(char const *s, unsigned int start, size_t len);
char			*ft_strjoin(char const *s1, char const *s2);
char			*ft_strtrim(char const *s1, char const *set);
char			**ft_split(char const *s, char c);
char			*ft_itoa(int n);
char			*ft_strmapi(char const *s, char (*f)(unsigned int, char));
void			ft_striteri(char *s, void (*f)(unsigned int, char *));
void			ft_putchar_fd(char c, int fd);
void			ft_putstr_fd(char *s, int fd);

#endif