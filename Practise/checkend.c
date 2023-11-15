#include<stdio.h>

int main(){
    int x = 1;
    char *byte = (char *)&x;
    if(*byte == 1){
        printf("Little endian");
    }
    else{
        printf("Big endian");
    }
}