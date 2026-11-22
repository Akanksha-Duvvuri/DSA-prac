#include <stdio.h>

int findIndex(int a[], int low, int high) {
    if (low > high)
        return -1;

    int mid = low + (high - low) / 2;

    if (a[mid] == mid)
        return mid;

    if (a[mid] > mid)
        return findIndex(a, low, mid - 1);

    return findIndex(a, mid + 1, high);
}

int main() {
    int a[] = {-3, -1, 0, 3, 5, 7, 9};
    int n = sizeof(a) / sizeof(a[0]);

    printf("%d", findIndex(a, 0, n - 1));

    return 0;
}
