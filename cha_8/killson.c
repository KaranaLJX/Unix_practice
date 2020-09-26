#include <stdio.h>
#include <sys/wait.h>
#include <unistd.h>
int main()
{
    pid_t pid;
    if ((pid = fork()) < 0)
        printf("fork error\n");
    else if (pid = 0)
    {
        if ((pid == fork()) < 0)
            printf("fork error\n");
        else if (pid > 0)
            exit(0);
        sleep(2);
        printf("second child,parent id= %d\n", getppid());
        exit(0);
    }
    if (waitpid(pid, NULL, 0) != pid)
        printf("wait error\n");
}