#include <stdio.h>
#include <unistd.h>
int main()
{
    pid_t pid;
    if ((pid =fork()) < 0)
        printf("fork error\n");
    else if (pid == 0)
    {
        if (execlp("/home/karana/unix_practice/cha_8/testexplain",
                   "testexplain", "myarg1", "myarg2", (char *)0) < 0)
            printf("execl error");
    }
    if (waitpid(pid, NULL, 0) < 0)
        perror("waited error\n");
}