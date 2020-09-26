#include<stdlib.h>
int main(int argc,char *argv[]){
    printf("argc");
    int i=0;
    for(int i=0;i<argc;i++){
        printf("argv[%d]: %s\n",i,argv[i]);
    }
}