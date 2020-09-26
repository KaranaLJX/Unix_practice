#include<stdlib.h>
static void exit1(){
    printf("first exit handler\n");

}
static void exit2(){
    printf("second exit handler\n");

}
int main(){
    if(atexit(exit1)){
        printf("can not register exit1\n");
    }
    if(atexit(exit2)){
        printf("can not register exit2\n");
    }
    printf("main done!");
    return 0;
}
