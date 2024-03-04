#include "pipex.h"

int ft_strcmp(char *s1, char *s2)
{
    size_t i;

    i = 0;
    if(!s1)
        return(0);
    while(s1[i] || s2[i])
    {
        if(s1[i] == s2[i])
            i++;
        return(s2[i] - s2[i]);
    }
    return(0);
}
char    ft_putstr(char *s)
{
    int i;

    i = 0;
    if (s[i] == '\0')
        return (0);
    while (s[i] != '\0')
    {
        write(1, &s[i], 1);
        i++;
    }
    return (0);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*all;
	size_t	i;

	i = 0;
	if (start >= ft_strlen(s))
		return (ft_strdup(""));
	if (len > ft_strlen(s) - start)
		len = ft_strlen(s) - start;
	all = (char *)malloc(sizeof(char) * len + 1);
	if (!all)
		return (NULL);
	while (i < len && s[start + i])
	{
		all[i] = s[start + i];
		i++;
	}
	all[i] = '\0';
	return (all);
}

char *find_env_path(char *pathname, char **env)
{
    int     i;
    int     j;
    char    *str;

    i = 0;
    while(env[i])
    {
        j = 0;
        while(env[i][j] && env[i][j] != '=')
            j++;
        str = ft_substr(env[i], 0, j);
        if (ft_strcmp(str, pathname) == 0)
        {
            free(str);
            return (env[i] + j + 1);
        }
        free(str);
        i++;
    }
    return (NULL);
}

char    *find_path(char **cmd, char **env)
{
    int     i;
    char	**path;
	char	**cmd_split;
	char	*path_exec;
	char	*find_env;

    i = -1;
    find_env = find_env_path("PATH", env);
    if(!find_env)
        error(5);
    path = ft_split(find_env, ':');
    cmd_split = ft_split(*cmd, ' ');
    while(path[++i])
    {
        path_exec = ft_strjoin(ft_strjoin(path[i], "/"), cmd_split[0]);
        if(access(path_exec, F_OK | X_OK) == 0)
        {
            free(cmd_split);
            return(path_exec);
        }
        free(path_exec);
    }
    free(cmd_split);
    free(path);
    return(*cmd);

}

void ft_free(char **str)
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
