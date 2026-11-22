#include<stdio.h>

void merge(int *arr, int low, int mid, int high){
    int temp[8];
    int i = low, j = mid + 1, k = 0;

    while(i <= mid && j <= high){
        if(arr[i] <= arr[j]){
            temp[k++] = arr[i++];
        }else {
            temp[k++] = arr[j++];
        }
    }

    while(i <= mid){
        temp[k++] = arr[i++];
    }

    while(j <= high){
        temp[k++] = arr[j++];
    }

    for(int i=0; i<k; i++){
        arr[low + i] = temp[i];
    }
}

void mergeSort(int*arr, int low, int high){
    if(low >= high) return;

    int mid = low + (high - low) / 2;

    mergeSort(arr, low, mid);
    mergeSort(arr, mid + 1, high);

    merge(arr, low, mid, high);
}

void removeDuplicates(int *arr, int n){
    if(n == 0) return;

    int j = 0;

    for(int i=1; i<n; i++){
        if(arr[i] != arr[j]){
            j++;
            arr[j] = arr[i];
        }
    }

     for (int i = 0; i <= j; i++)
        printf("%d ", arr[i]);
}

int main(){
    int arr[8] = {4, 2, 5, 2, 1, 4, 5, 3};

    mergeSort(arr, 0, 7);
    removeDuplicates(arr, 8);
    return 0;
}