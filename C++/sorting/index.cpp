#include<iostream>
using namespace std;

int match(int *arr, int start, int end){
    if(start > end) return -1;

    while(start <= end) {
        int mid =  start + (end - start) / 2;

        if(arr[mid] > mid){
            start = mid+1;
        }else if(arr[mid] < mid){
            end = mid-1;
        }else {
            return mid;
        }
    }
    return -1;
}

int main(){
    int arr[] = {-3, -1, 0, 3, 5, 7, 9};
    int n = sizeof(arr) / sizeof(int);

    int result = match(arr, 0, n-1);

    cout << result << endl;
    return 0;
}