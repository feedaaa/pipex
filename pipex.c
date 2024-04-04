/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:15:28 by ffidha            #+#    #+#             */
/*   Updated: 2024/04/03 17:15:33 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h" // Include necessary header file

// Function to execute a command
void	execute(char *cmd, char **env)
{
	char	**cmd_split; // Array to store split command
	char	*path; // Path to the executable command

	// Split the command into individual arguments
	cmd_split = ft_split(cmd, ' ');
	
	// Check if command is empty
	if (!cmd_split[0])
		error(4); // Exit with error 4
	
	// Find the path to the executable command
	path = find_path(&cmd_split[0], env);
	
	// Execute the command
	if (execve(path, cmd_split, env) == -1)
	{
		// Print error message if command not found
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("command not found: ", STDERR_FILENO);
		ft_putendl_fd(cmd_split[0], STDERR_FILENO);
		ft_free(cmd_split); // Free memory allocated for split command
		exit(EXIT_FAILURE); // Exit with failure status
	}
}

// Function executed by the parent process
void	parent_process(char **av, int *pipefd, char **env)
{
	int		fd;

	// Open the output file for writing
	fd = open(av[4], O_WRONLY | O_CREAT | O_TRUNC, 0777);
	if (fd == -1)
<<<<<<< HEAD
	{
		perror(av[4]);
		exit(EXIT_FAILURE);
	}
=======
		perror(av[4]); // Exit with error 8 if file cannot be opened
	
	// Redirect standard output to the output file
>>>>>>> 43fabb5bebc0d1a29cba17b651393750d54b4aa2
	dup2(fd, 1);
	
	// Redirect standard input to the read end of the pipe
	dup2(pipefd[0], 0);
	
	// Close the write end of the pipe
	close(pipefd[1]);
	
	// Execute the command specified by av[3]
	execute(av[3], env);
}

// Function executed by the child process
void	child_process(char **av, int *pipefd, char **env)
{
	int		fd;

	// Open the input file for reading
	fd = open(av[1], O_RDONLY, 0777);
	if (fd == -1)
<<<<<<< HEAD
	{
		perror(av[1]);
		exit(EXIT_FAILURE);
	}
=======
		perror(av[1]); // Exit with error 8 if file cannot be opened
	
	// Redirect standard input to the input file
>>>>>>> 43fabb5bebc0d1a29cba17b651393750d54b4aa2
	dup2(fd, 0);
	
	// Redirect standard output to the write end of the pipe
	dup2(pipefd[1], 1);
	
	// Close the read end of the pipe
	close(pipefd[0]);
	
	// Execute the command specified by av[2]
	execute(av[2], env);
}

// Main function
int	main(int ac, char **av, char **env)
{
	int		pipefd[2];
	pid_t	pid;
	int		status;

	// Check if environment variables are provided
	if (!*env || !env)
	{
		error(6); // Exit with error 6 if environment variables are missing
		exit(1);
	}
	
	// Check if the correct number of arguments are provided
	if (ac != 5)
		error(1); // Exit with error 1 if incorrect number of arguments
	
	// Create a pipe
	if (pipe(pipefd) < 0)
		error(2); // Exit with error 2 if pipe creation fails
	
	// Fork a child process
	pid = fork();
	if (pid < 0)
		error(3); // Exit with error 3 if fork fails
	
	// Child process executes child_process function
	if (pid == 0)
		child_process(av, pipefd, env);
	
	// Parent process executes parent_process function
	pid = fork();
	if (pid < 0)
		error(3); // Exit with error 3 if fork fails
	if (pid != 0)
		parent_process(av, pipefd, env);
	
	// Wait for child process to complete
	wait(&status);
	
	// Exit with the exit status of the child process
	exit(WEXITSTATUS(status));
}
