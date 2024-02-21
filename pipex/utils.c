/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 14:58:02 by ffidha            #+#    #+#             */
/*   Updated: 2024/02/20 12:52:54 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

/* searches through the environment variable for the required name
it iterates through the string to find the first '=' character then
use substr to find the string after '=' charecter. then uses strcmp to 
match the string with the given variable name and returns a
 pointer to the portion 
of the sting after the '=' character. if no matching env variable is found the 
function returns NULL */

char	*find_env(char *name, char **env)
{
	int		i;
	int		j;
	char	*str;

	i = 0;
	while (env[i])
	{
		j = 0;
		while (env[i][j] && env[i][j] != '=')
			j++;
		str = ft_substr(env[i], 0, j);
		if (ft_strcmp(str, name) == 0)
		{
			free(str);
			return (env[i] + j + 1);
		}
		free(str);
		i++;
	}
	return (NULL);
}
/* This function finds and returns the full path of the command from the 
env variable first the function finds the env variable where "PATH" 
is specified using find_env function
then it splits the env variable using ':' as a delimiter.
the split_cmd array is populated by spltting the cmd variable 
using space character 
as delimiter a loop is started which will iterate through each directory in the 
full_path variable a partial path variable is created by adding '/' to the
 end of the current directory from the full path variable an exec_path variable 
 is created by adding the first string of the split cmd variable to the
end of partial path
the access function is used to check if the file exits (F_OK) and 
is executable (X_OK).
if the file exists and is executable free everything and return exec path
if a valid path is not found return cmd */
char	*find_path(char *cmnd, char **env)
{
	int		i;
	char	**full_path;
	char	**split_cmd; 
	char	*exec_path;
	char	*get_env_var;

	i = -1;
	get_env_var = find_env("PATH", env);
	if (!get_env_var)
		error(5);
	full_path = ft_split(get_env_var, ':');
	split_cmd = ft_split(cmnd, ' ');
	while (full_path[++i])
	{
		exec_path = ft_strjoin(ft_strjoin(full_path[i], "/"), split_cmd[0]);
		if (access(exec_path, F_OK | X_OK) == 0)
		{
			free(split_cmd);
			return (exec_path);
		}
		free(exec_path);
	}
	free(split_cmd);
	free(full_path);
	return (cmnd);
}
