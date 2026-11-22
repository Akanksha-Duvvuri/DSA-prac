#include<stdio.h>
#include<stdlib.h>

int compare(const void *a, const void *b){
    return (*(int *)a - *(int *)b);
}

int majorityElement(int *a, int n){
    if(n == 0) return -1;

    qsort(a, n, sizeof(int), compare);

    int count = 0;

    for(int i=0; i<n; i++){
        if(a[i] == a[i - 1]){
            count++;
        } else {
            count = 1;
        }

        if(count > n/2) return a[i];
    }
    return -1;
}

int main(){
    int a[] = {3, 2, 3, 4, 3, 3, 5, 3};
    int n = 8;

    printf("%d", majorityElement(a, n));
    return 0;
}