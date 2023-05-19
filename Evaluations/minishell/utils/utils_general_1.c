/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils_general_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: asepulve <asepulve@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/21 02:22:59 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/19 19:01:39 by asepulve         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./utils.h"

void	ft_swap(char *x, char *y)
{
	char	tmp;

	tmp = *y;
	*y = *x;
	*x = tmp;
}

void	free_env(t_env *env)
{
	t_env	*ptr;

	while (env)
	{
		ptr = env->next;
		if (env->name)
			free(env->name);
		if (env->value)
			free(env->value);
		if (env)
			free(env);
		env = ptr;
	}
	if (env)
		free(env);
}

int	check_words(char const *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] != ' ')
			return (1);
		i++;
	}
	return (0);
}
