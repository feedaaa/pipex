/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/08 13:20:59 by ffidha            #+#    #+#             */
/*   Updated: 2024/03/10 13:31:33 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "./libft/libft.h"
# include <fcntl.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/stat.h>
# include <sys/types.h>
# include <sys/wait.h>
# include <unistd.h>

# define RED_C "\033[0;31m"

// srcs
void	execute(char *cmd, char **env);
void	parent_process(char **av, int *pipefd, char **env);
void	child_process(char **av, int *pipefd, char **env);
// utils
char	*find_path(char **cmd, char **env);
char	*find_env_path(char **env);
int		error2(int error_code);
int		error(int error_code);
void	ft_free(char **str);

#endif
