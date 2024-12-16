void    cmd_exec(char **envp, char **argv, int index)
{
    /**/
}

void    child_process(int   fd[2], char **argv, char **envp)
{
    /**/
}

void    parent_process(int  fd[2], char **argv, char **envp)
{
    /**/
}

int main(int    argc, char  **argv, char **envp)
{
    pid_t   pid;
    int fd[2];

    if(envp == NULL || envp[0] || path_finder(envp) == 0)
        error();
    if (argc != 5)
        error();
    if(check_fd(argv[1]))
        error();
    if (check_cmd(envp, argv, 2))
}