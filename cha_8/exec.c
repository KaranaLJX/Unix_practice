#include <unistd.h>
#include <sys/wait.h>
#include <stdio.h>
#include <errno.h>
#include <string.h>
#include <stdlib.h>

char *env_init[] = {"USER=UNKNOWN", "PATH=/TMP", NULL};
int main(void)
{
    pid_t pid;
    if ((pid = fork()) < 0)
        printf("fork error\n");
    else if (pid == 0)
    {
        if (execle("/home/karana/unix_practice/cha_8/echoall", "echoall",
                   "myarg1", "MY ARG2", (char *)0, env_init) < 0)
        {

            printf("execle error\n");
            puts(strerror(errno));
        }
    }
    if (waitpid(pid, NULL, 0) < 0)
    {
        puts(strerror(errno));
        printf("wait error\n");
    }
    char *m = getenv("PATH");
    m = strcat(m, ":/home/karana/unix_practice/cha_8");
    setenv("PATH", m, 1);
    if ((pid = fork()) < 0)
        printf("fork error\n");
    else if (pid == 0)
    {
        if (execlp("echoall", "echoall", "only one arg", (char *)0) < 0)
        {
            puts(strerror(errno));
            printf("execlp error\n");
        }
    }
    return 0;
}