/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcns.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:11:26 by ffidha            #+#    #+#             */
/*   Updated: 2024/03/15 12:21:58 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

char	*find_env_path(char **env)
{
	int	i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH", 4))
		i++;
	if (!env[i])
	{
		error(7);
		exit(1);
		return (NULL);
	}
	return (env[i] + 5);
}

char	*find_path(char **cmd, char **env)
{
	int		i;
	char	**path;
	char	**cmd_split;
	char	*path_exec;
	char	*find_env;

	i = -1;
	find_env = find_env_path(env);
	if (!find_env)
		error(5);
	path = ft_split(find_env, ':');
	cmd_split = ft_split(*cmd, ' ');
	while (path[++i])
	{
		path_exec = ft_strjoin(ft_strjoin(path[i], "/"), cmd_split[0]);
		if (access(path_exec, F_OK | X_OK) == 0)
		{
			return (free(cmd_split), path_exec);
		}
		else if (path[i + 1] == NULL && access(path_exec, F_OK | X_OK) != 0)
		{
			error(4);
		}
		free(path_exec);
	}
	return (free(path), free(cmd_split), *cmd);
}

void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]);
		i++;
	}
	free(str);
}
