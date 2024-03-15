/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:15:28 by ffidha            #+#    #+#             */
/*   Updated: 2024/03/15 11:35:07 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	execute(char *cmd, char **env)
{
	char	**cmd_split;
	char	*path;

	cmd_split = ft_split(cmd, ' ');
	if (!cmd_split[0])
		error(4);
	path = find_path(&cmd_split[0], env);
	if (execve(path, cmd_split, env) == -1)
	{
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("command not found: ", STDERR_FILENO);
		ft_putendl_fd(cmd_split[0], STDERR_FILENO);
		ft_free(cmd_split);
		exit(0);
	}
}

void	parent_process(char **av, int *pipefd, char **env)
{
	int		fd;

	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
		error(8);
	dup2(fd, 1);
	dup2(pipefd[0], 0);
	close(pipefd[1]);
	execute(av[3], env);
}

void	child_process(char **av, int *pipefd, char **env)
{
	int		fd;

	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
		error(8);
	dup2(fd, 0);
	dup2(pipefd[1], 1);
	close(pipefd[0]);
	execute(av[2], env);
}

int	main(int ac, char **av, char **env)
{
	int		pipefd[2];
	pid_t	pid;

	if (!*env || !env)
	{
		error(6);
		exit(1);
	}
	if (ac != 5)
		error(1);
	if (pipe(pipefd) < 0)
		error(2);
	pid = fork();
	if (pid < 0)
		error(3);
	if (pid == 0)
		child_process(av, pipefd, env);
	pid = fork();
	if (pid < 0)
		error(3);
	if (pid != 0)
		parent_process(av, pipefd, env);
}
