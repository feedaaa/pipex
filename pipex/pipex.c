/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/06 12:14:50 by ffidha            #+#    #+#             */
/*   Updated: 2024/02/20 12:54:39 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmnd, char **env)
{
	char	**split_cmd;
	char	*path;

	split_cmd = ft_split(cmnd, ' ');
	if (!split_cmd[0])
		error(6);
	path = find_path(split_cmd[0], env);
	if (execve(path, split_cmd, env) == -1)
	{
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("Command not found : ", STDERR_FILENO);
		ft_putendl_fd(split_cmd[0], STDERR_FILENO);
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_free(split_cmd);
		exit(0);
	} 
}
/*parent process opens the file for writing. duplicates the fd into stdout so
any output is written to the file opened. 
*/
void	parent_process(char **av, int *pipe_fd, char **env) //write
{
	int fd;
	fd = open(av[1], O_RDONLY, 0777);
	dup2(fd, STDOUT_FILENO);
	dup2(pipe_fd[0], STDIN_FILENO);
	close(pipe_fd[1]);
	execute(av[3], env);
}

void	child_process(char **av, int *pipe_fd, char **env) //read
{
	int		fd;

	fd = open(av[1], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	dup2(fd, STDOUT_FILENO);
	dup2(pipe_fd[1], 1);
	close(pipe_fd[1]);
	execute(av[2], env);
}
// opening a pipe and forking the process

