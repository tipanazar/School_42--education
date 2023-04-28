/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:05:04 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/28 20:45:58 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

// # ifndef BUFFER_SIZE
// #  define BUFFER_SIZE 9
// # endif

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 20
# endif

char	*get_next_line(int fd);
int		ft_strlength(char *str);
void	ft_strcpy(char *src, char *dest, int len);
int		ft_str_with_new_line_length(char *str);
int		ft_check_str_new_line(char *str);
char	*ft_strjoin(char *s1, char *s2);

#endif
