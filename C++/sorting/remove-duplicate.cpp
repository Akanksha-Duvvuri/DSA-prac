#include<iostream>
#include<algorithm>
using namespace std;

void merge(int arr[], int left, int mid, int right) {
    int temp[right - left + 1];
    int i = left, j = mid + 1, k = 0;

    while (i <= mid && j <= right) {
        if (arr[i] <= arr[j])
            temp[k++] = arr[i++];
        else
            temp[k++] = arr[j++];
    }

    while (i <= mid)
        temp[k++] = arr[i++];

    while (j <= right)
        temp[k++] = arr[j++];

    for (i = 0; i < k; i++)
        arr[left + i] = temp[i];
}

void mergeSort(int arr[], int left, int right) {
    if (left >= right)
        return;

    int mid = left + (right - left) / 2;

    mergeSort(arr, left, mid);
    mergeSort(arr, mid + 1, right);
    merge(arr, left, mid, right);
}


void removeDuplicates(int arr[], int n) {
    int j = 0;

    for (int i = 1; i < n; i++) {
        if (arr[i] != arr[j]) {
            j++;
            arr[j] = arr[i];
        }
    }

    for (int i = 0; i <= j; i++){
        cout << arr[i] << " ";
    }

    cout << endl;
}

int main(){
    int arr[] = {4, 2, 5, 2, 1, 4, 5, 3};
    int n = sizeof(arr) / sizeof(int);

    mergeSort(arr, 0, n - 1);
    removeDuplicates(arr, n);
    return 0;
}