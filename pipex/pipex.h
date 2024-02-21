/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ffidha <ffidha@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/25 16:19:26 by ffidha            #+#    #+#             */
/*   Updated: 2024/02/20 12:03:58 by ffidha           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# ifndef PIPEX_H
# define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>
# include "./libft/libft/libft.h"

# define RED_C	"\033[0;31m"

/* ------SRCS------ */
void	execute(char *cmd, char **env);
void	parent_process(char **av, int *pipe_fd, char **env);
void	child_process(char **av, int *pipe_fd, char **env);
char	*find_env(char *name, char **env);
char	*find_path(char *name, char **env);

/* ------UTILS------ */

// void	error(int code);
// void	error2(int code);
void	ft_putstr_fd(char *s, int fd);
void	ft_putendl_fd(char *s, int fd);
char	*ft_substr(char const *s, unsigned int start, size_t len);
char	**ft_split(char const *s, char c);
#endif