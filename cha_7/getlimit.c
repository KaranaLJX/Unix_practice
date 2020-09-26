#include <stdlib.h>
#include <sys/resource.h>
#define doit(name) pr_limit(#name, name)
static void pr_limit(char *name, int resource)
{
    struct rlimit limit;
    unsigned long long lim;
    if (getrlimit(resource, &limit) < 0)
    {
        printf("getlimit error for #%s#  \n");
        return;
    }
    printf("%14s ", name);
    if (limit.rlim_cur == RLIM_INFINITY)
        printf("(infinite) ");
    else
    {
        lim = limit.rlim_cur;
        printf("%10lld ",lim);
    }
    if (limit.rlim_max == RLIM_INFINITY)
        printf("(infinite) ");
    else
    {
        lim = limit.rlim_max;
        printf("%10lld ",lim);
    }
    putchar((int)'\n');
}
int main(){
    doit(RLIMIT_CORE);
    doit(RLIMIT_CPU);
    doit(RLIMIT_DATA);
    doit(RLIMIT_FSIZE);
}