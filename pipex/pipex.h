#ifndef PIPEX_H
#define PIPEX_H

# include <unistd.h>
# include <stdlib.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/stat.h>
# include <sys/wait.h>

//srcs
void	execute(char *cmd, char **env);
void	parent_process(char **av, int fd, char **env);
void    child_process(char **av, int fd, char **env);

//utils
void    find_path(char **cmd, char **env);
char    *find_env_path(char *command, char **env);
char	**ft_split(const char *s, char c);
char	*ft_strjoin(char const *s1, char const *s2);
char	*ft_substr(char const *s, unsigned int start, size_t len);
int     ft_strcmp(char *s1, char *s2);
#endif