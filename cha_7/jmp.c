#include <stdlib.h>
#include <setjmp.h>
static jmp_buf jmpbuf;
static int gloval;
static void f2()
{
    longjmp(jmpbuf, 1);
}
static void f1(int i, int j, int k, int l, int m)
{

    printf("before jmp:\n");
    printf("glo: %d, reg: %d, vol: %d, auto: %d, stat: %d\n", i, j, k, l, m);
    f2();
}
int main()
{
    register int regval;
    volatile int volval;
    int autoval;
    static int statval;
    gloval = 1, regval = 2, volval = 3, autoval = 4, statval = 5;
    if (setjmp(jmpbuf) == 1)
    {
        printf("after jmp:\n");
        printf("glo: %d, reg: %d, vol: %d, auto: %d, stat: %d\n", gloval, regval, volval, autoval, statval);
    }
    printf("haha");
    gloval = 11,
    regval = 12, volval = 13, autoval = 14, statval = 15;
    f1(gloval, regval, volval, autoval, statval);
    printf("haha");
    return 0;
}