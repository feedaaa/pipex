/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:19:14 by ffidha            #+#    #+#             */
/*   Updated: 2024/02/20 12:10:49 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"

int	main(int ac, char **av, char **env)
{
	int end[2];
	pid_t pid;

	if (ac != 5)
	{
		perror("less than 5 arguments!");
		error(1);
	}
	if (pipe(end) < 0)
		error(2);
	pid = fork();
	if (pid == -1)
		error(3);
	if (pid == 0)
		child_process(av, end, env);
	parent_process(av, end, env);
}
