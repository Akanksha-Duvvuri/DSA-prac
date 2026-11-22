#include<stdio.h>
#include<limits.h>

int getValue(int a[], int n, int i){
    if(i >= n){
        return INT_MAX;
    }
    return a[i];
}

int binarySearch(int *a, int n, int low, int high, int x){
    while(low <= high){
        int mid = low + (high - low)/2;
        int value = getValue(a, n, mid);

        if(value == x){
            return mid;
        }else if(value < x){
            low = mid + 1;
        }else{
            high = mid - 1;
        }
    }
    return -1;
}

int exponentialSearch(int *a, int n, int x){
    if(n == 0) return -1;

    if(a[0] == x){
        return 0;
    }

    int i=1;

    while(getValue(a, n, i) < x){
        i *= 2;
    }

    return binarySearch(a, n, i/2 +1, i, x);
}

int main(){
    int a[] = {1, 4, 6, 9, 15, 20, 28};
    int n = sizeof(a) / sizeof(a[0]);
    int x = 18;

    printf("%d", exponentialSearch(a, n, x));
    return 0;
}