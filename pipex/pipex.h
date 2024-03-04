#ifndef PIPEX_H
# define PIPEX_H

# include "libft/libft.h"
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
char	*find_env_path(char *command, char **env);
int		ft_strcmp(char *s1, char *s2);
int		error2(int error_code);
int		error(int error_code);
char	ft_putstr(char *s);
void	ft_free(char **str);

#endif
