#include<iostream>
#include<algorithm>
using namespace std;

void printArr(int *arr, int n){
    for(int i=0; i<n; i++){
        cout << arr[i] << " ";
    }
    cout << endl;
}

int partition(int *arr, int s, int e){
    int i = s - 1;
    int pivot = arr[e];

    for(int j=s; j<e; j++){
        if(arr[j] <= pivot){
            i++;
            swap(arr[i], arr[j]);
        }
    }
    i++;
    swap(arr[i], arr[e]);

    return i;
}

void quick(int *arr, int s, int e){
    if(s >= e){
        return;
    }

    int pivotidx = partition(arr, s, e);

    quick(arr, s, pivotidx-1);
    quick(arr, pivotidx+1, e);
}

int main(){
    int arr[6] = {6, 3, 7, 5, 2, 4};

    quick(arr, 0, 5);

    printArr(arr, 6);
    return 0;
}