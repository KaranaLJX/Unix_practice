#include<stdio.h>
int main(int argv,char*args[]){
    for(int i=0;i<argv;i++){
        printf("ARGS[%d]: %s\n",i,args[i]);
    }
}