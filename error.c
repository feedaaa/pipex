/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:17:51 by ffidha            #+#    #+#             */
/*   Updated: 2024/03/20 14:30:12 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	error2(int error_code)
{
	if (error_code == 4)
	{
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("command not found: \n", 2);
	}
	if (error_code == 5)
	{
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("PATH not found :/ \n", 2);
	}
	if (error_code == 6)
	{
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("No environment found :/ \n", 2);
	}
	if (error_code == 7)
	{
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("No path variable found in environment :/ \n", 2);
	}
	exit(EXIT_FAILURE);
}

int	error(int error_code)
{
	if (error_code == 1)
	{
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("less than 5 arguments :/ \n", 2);
		ft_putstr_fd("usage: ./pipex file1 cmd1 cmd2 file2\n", 2);
	}
	if (error_code == 2)
	{
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("pipe error :/ \n", 2);
	}
	if (error_code == 3)
	{
		ft_putstr_fd(RED_C, STDERR_FILENO);
		ft_putstr_fd("pid error :/ \n", 2);
	}
	if (error_code >= 4 && error_code <= 8)
		error2(error_code);
	exit(0);
}
