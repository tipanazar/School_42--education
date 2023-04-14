/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nkarpeko <nkarpeko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 13:21:48 by nkarpeko          #+#    #+#             */
/*   Updated: 2023/04/14 15:57:24 by nkarpeko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_H
# define LIBFT_H

# include <stdbool.h>
# include <stdio.h>
# include <stdlib.h>

void	*ft_memset(void *ptr, int value, int num);
int		ft_strlen(char *str);
void	*ft_memcpy(void *dest, void *src, int num);
int		ft_strncmp(char *s1, char *s2, int n);

#endif