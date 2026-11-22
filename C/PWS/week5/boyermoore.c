#include<stdio.h>

int majorityElement(int *a, int n){
    if(n == 0) return -1;

    int candidate = 0;
    int count = 0;

    for(int i=0; i<n; i++){
        if(count == 0){
            candidate = a[i];
            count = 1;
        }else if(a[i] == candidate){
            count++;
        }else {
            count--;
        }
    }
    count = 0;

    for(int i=0; i<n; i++){
        if(a[i] == candidate){
            count++;
        }
    }

    if(count > n/2){
        return candidate;
    }

    return -1;
}

int main(){
    int a[] = {3, 2, 3, 4, 3, 3, 5, 3};
    int n = 8;

    printf("%d", majorityElement(a, n));
    return 0;
}