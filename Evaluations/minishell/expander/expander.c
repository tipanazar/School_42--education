/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expander.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mvicente <mvicente@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/03 12:08:31 by asepulve          #+#    #+#             */
/*   Updated: 2023/05/19 20:10:12 by mvicente         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./expander.h"

extern int	g_exit_s;

static char	*get_var_name(char *str)
{
	char	*var_name;
	int		i;

	if (!str || (!ft_isalpha(str[0]) && str[0] != '_' && str[0] != '?'))
		return (ft_strdup(""));
	if (str[0] == '?')
		return (ft_strdup("?"));
	i = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
		i++;
	var_name = ft_calloc(i + 1, sizeof(char));
	if (!var_name)
		return (NULL);
	i = 0;
	while (str[i] && (ft_isalnum(str[i]) || str[i] == '_'))
	{
		var_name[i] = str[i];
		i++;
	}
	return (var_name);
}

static char	*concat_env_to_str(char *current, char *var_name,
							int rest, char **envp)
{
	char	*env_value;
	char	*new_str;

	if (var_name[0] == '?')
		env_value = ft_itoa(g_exit_s);
	else
		env_value = get_env_value(var_name, envp);
	if (!env_value)
		return (NULL);
	new_str = ft_calloc(ft_strlen(env_value) + 2 + \
				ft_strlen(current) + rest + 2, sizeof(char));
	if (!new_str)
		return (NULL);
	ft_strlcpy(new_str, current, ft_strlen(current) + 1);
	ft_strlcat(new_str, env_value, ft_strlen(current) + \
	ft_strlen(env_value) + 1 + 2);
	free(env_value);
	free(current);
	return (new_str);
}

static void	expande_to_new_str(char *str, char **new_str, int *i, int *j)
{
	char	*var_name;

	var_name = NULL;
	var_name = get_var_name(&str[*i + 1]);
	*new_str = concat_env_to_str(*new_str, var_name,
			ft_strlen(&str[*i + 1 + ft_strlen(var_name)]), *env());
	if (!new_str)
	{
		write(2, "WE COULDN'T ALLOCATE MEMORY.\n", 30);
		g_exit_s = EXIT_FAILURE;
		exit(g_exit_s);
	}
	*i += ft_strlen(var_name) + 1;
	*j = ft_strlen(*new_str);
	free(var_name);
}

static void	expand_rules(char *str, char **new_str, int *i, int *j)
{
	int		single_quotes_len;

	single_quotes_len = 0;
	if (str[*i] == '\'')
	{
		single_quotes_len = jump_quotes(&str[*i]);
		ft_strlcat(*new_str, &str[*i], ft_strlen(*new_str) \
		+ single_quotes_len + 1);
		*j += single_quotes_len;
		*i += single_quotes_len;
	}
	else if (str[*i] == '"')
	{
		(*new_str)[(*j)++] = str[(*i)++];
		while (str[*i] && str[*i] != '"')
		{
			if (ft_isvar(&str[*i]))
				expande_to_new_str(str, new_str, i, j);
			else
				(*new_str)[(*j)++] = str[(*i)++];
		}
		(*new_str)[(*j)++] = str[(*i)++];
	}
	else if (ft_isvar(&str[*i]))
		expande_to_new_str(str, new_str, i, j);
}

char	*expander(char *str)
{
	char	*new_str;
	int		i;
	int		j;

	j = 0;
	i = 0;
	new_str = ft_calloc(ft_strlen(str) + 2, sizeof(char));
	if (!new_str)
		return (NULL);
	while (str[i])
	{
		if (str[i] == '\'' || str[i] == '"' || ft_isvar(&str[i]))
			expand_rules(str, &new_str, &i, &j);
		else
			new_str[j++] = str[i++];
	}
	if (str)
	{
		free(str);
		str = NULL;
	}
	return (new_str);
}
