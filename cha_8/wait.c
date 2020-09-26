#include <stdio.h>
#include <sys/wait.h>
static void pr_name(int status)
{
    if (WIFEXITED(status))
    {
        printf("normal termination ,exit status=%d\n", WEXITSTATUS(status));
    }
    else if (WIFSIGNALED(status))
    {
        printf("abnormal termination ,signal number = %d%s\n", WTERMSIG(status),
#ifdef WCOREDUMP
               WCOREDUMP(status) ? "core file generated" : ""
#endif
        );
    }
    else if (WIFSTOPPED(status))
        printf("child stop,signal number=%d\n", WSTOPSIG(status));
}
int main()
{
    pid_t pid;
    int status;
    if ((pid = fork()) < 0)
        printf("fork error\n");
    else if (pid == 0)
        exit(0);
    if (wait(&status) != pid)
        printf("wait error\n");
    else
        pr_name(status);
    if ((pid = fork()) < 0)
        printf("fork error\n");
    else if (pid == 0)
        abort();
    if (wait(&status) != pid)
        printf("wait error\n");
    else
        pr_name(status);
    if ((pid = fork()) < 0)
        printf("fork error\n");
    else if (pid == 0)
        status/=0;
    if (wait(&status) != pid)
        printf("wait error\n");
    else
        pr_name(status);
    return 0;
}