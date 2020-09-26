#include <stdlib.h>
#include <unistd.h>
#include <stdio.h>
int globvar = 6;
char buf[] = "a write to stdout\n";
int main()
{
    int var = 88;
    pid_t pid;
    printf("pid = %d\n", getpid());
    if (write(STDOUT_FILENO, buf, sizeof(buf) - 1) != sizeof(buf) - 1)
    {
        printf("write error\n");
    }
    printf("before fork\n");
    if ((pid = fork()) < 0)
    {
        printf("fork error");
    }
    else
    {
        if (pid == 0)
        {
            puts("In child proc");
            globvar++;
            var++;
        }
        else
        {
            sleep(2);
            puts("In parent proc");
            // sleep(20);
            // printf("pid= %d ,globalvar= %d ,var= %d\n", pid, globvar, var);
        }
    }
    printf("pid= %d ,globalvar= %d ,var= %d\n", pid, globvar, var);
    return 0;
}
