#include<stdio.h>
int main(){
    int arr[]={3,4,5,1,2};
    int arr2[5];
    arr2[0] = arr[0];
    int j=1;
    for(int i=1;i<5;i++){
        arr2[j] = arr2[j-1] + arr[i];
        j++; 
    }
    for(int i=0;i<5;i++){
        printf("%d  ",arr2[i]);
    }
}