/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/23 19:05:04 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/05/04 21:27:06 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <limits.h>
# include <stdio.h>
# include <stdlib.h>
# include <string.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 99999
# endif

char	*get_next_line(int fd);
int		ft_strlength(char *str);
int		ft_str_with_new_line_length(char *str);
int		ft_new_line_detector(char *str);
char	*ft_strjoin_to_new_line(char *s1, char *s2);
void	ft_remove_first_line(char *str);
void	ft_str_cleaner(char *str, int start);

#endif
