#include "pipex.h"

int error2(int errorcode)
{
    if(error_code == 4)
    {
        ft_putstr_fd(RED_C, STDERR_FILENO);
        ft_putstr("less than 5 arguments :/ \n");
        ft_putstr("usage: ./pipex file1 cmd1 cmd2 file2\n")
    }
    if(error_code == 5)
    {
        ft_putstr_fd(RED_C, STDERR_FILENO);
        ft_putstr("pipe error :/ \n");
    }
    if(error_code == 6)
    {
        ft_putstr_fd(RED_C, STDERR_FILENO);
        ft_putstr("pid error :/ \n");
    }
}


int error(int error_code)
{
    if(error_code == 1)
    {
        ft_putstr_fd(RED_C, STDERR_FILENO);
        ft_putstr("less than 5 arguments :/ \n");
        ft_putstr("usage: ./pipex file1 cmd1 cmd2 file2\n")
    }
    if(error_code == 2)
    {
        ft_putstr_fd(RED_C, STDERR_FILENO);
        ft_putstr("pipe error :/ \n");
    }
    if(error_code == 3)
    {
        ft_putstr("pid error :/ \n");
    }
    error2(errorcode);
    exit(errorcode);
}