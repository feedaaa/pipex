/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fcns.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:11:26 by ffidha            #+#    #+#             */
/*   Updated: 2024/03/19 11:46:03 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h" // Include necessary header file

// Function to find the PATH environment variable
char	*find_env_path(char **env)
{
	int	i;

	i = 0;
	// Find the PATH environment variable
	while (env[i] && ft_strncmp(env[i], "PATH", 4))
		i++;
	if (!env[i])
	{
		error(7); // Exit with error 7 if PATH environment variable is not found
		exit(1);
		return (NULL);
	}
	return (env[i] + 5); // Return the value of the PATH environment variable
}

// Function to find the full path of the executable command
char	*find_path(char **cmd, char **env)
{
	int		i;
	char	**path;
	char	**cmd_split;
	char	*path_exec;
	char	*find_env;

	i = -1;
	find_env = find_env_path(env); // Get the value of the PATH environment variable
	if (!find_env)
		error(5); // Exit with error 5 if PATH environment variable is not found
	path = ft_split(find_env, ':'); // Split the PATH variable into individual paths
	cmd_split = ft_split(*cmd, ' '); // Split the command into individual arguments
	while (path[++i]) // Iterate through each path in the PATH variable
	{
		// Concatenate the path with the command to get the full path of the executable
		path_exec = ft_strjoin(ft_strjoin(path[i], "/"), cmd_split[0]);
		// Check if the executable exists and is executable
		if (access(path_exec, F_OK | X_OK) == 0)
		{
			return (free(cmd_split), path_exec); // Free memory allocated for split command and return the full path
		}
		else if (path[i + 1] == NULL && access(path_exec, F_OK | X_OK) != 0)
			error(4); // Exit with error 4 if executable is not found in any path
		free(path_exec); // Free memory allocated for full path
	}
	return (free(path), free(cmd_split), *cmd); // Free memory allocated for path and split command and return original command
}

// Function to free memory allocated for an array of strings
void	ft_free(char **str)
{
	size_t	i;

	i = 0;
	while (str[i])
	{
		free(str[i]); // Free memory allocated for each string
		i++;
	}
	free(str); // Free memory allocated for array of strings
}
