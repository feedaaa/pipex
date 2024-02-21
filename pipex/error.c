/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/02/14 11:55:03 by ffidha            #+#    #+#             */
/*   Updated: 2024/02/20 12:07:27 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

void	error(int code)
{
	if (code == 1)
	{
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("Usage: ./pipex file1 cmd1 cmd2 file2 \n", STDERR_FILENO);
	}
	else if (code == 2)
	{
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("Pipe failed :/ \n", STDERR_FILENO);
	}
	else if (code == 3)
	{
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("Forking failed :/ \n", STDERR_FILENO);
		ft_putstr_fd(RED_C, STDERR_FILENO);
	}
	error2(code);
	exit(code);
}
void	error2(int code)
{	
	if (code == 4)
	{
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("Failed to open the file .... \n", STDERR_FILENO);
		ft_putstr_fd(RED_C, STDERR_FILENO);
	}
	else if (code == 5)
	{
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("Path not found .... \n", STDERR_FILENO);
		ft_putstr_fd(RED_C, STDERR_FILENO);
	}
	else if (code == 6)
	{
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("cmd1 or cmd2 is empty.....\n", STDERR_FILENO);
		ft_putstr_fd(RED_C, STDERR_FILENO);
	}
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