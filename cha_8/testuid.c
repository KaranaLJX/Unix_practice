#include<stdio.h>
#include<unistd.h>
#include<stdlib.h>
int main(){
    printf("real uis is %d,effective uid = %d\n",getuid(),geteuid());
    exit(0);
}