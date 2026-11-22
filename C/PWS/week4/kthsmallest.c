#include <stdio.h>
#include <limits.h>

int max(int a, int b) {
    return a > b ? a : b;
}

int min(int a, int b) {
    return a < b ? a : b;
}

int kthSmallest(int a[], int n, int b[], int m, int k) {
    if (n > m)
        return kthSmallest(b, m, a, n, k);

    if (k < 1 || k > n + m)
        return -1;

    int low = max(0, k - m);
    int high = min(k, n);

    while (low <= high) {
        int mid1 = low + (high - low) / 2;
        int mid2 = k - mid1;

        int l1 = (mid1 == 0) ? INT_MIN : a[mid1 - 1];
        int l2 = (mid2 == 0) ? INT_MIN : b[mid2 - 1];

        int r1 = (mid1 == n) ? INT_MAX : a[mid1];
        int r2 = (mid2 == m) ? INT_MAX : b[mid2];

        if (l1 <= r2 && l2 <= r1)
            return max(l1, l2);

        if (l1 > r2)
            high = mid1 - 1;
        else
            low = mid1 + 1;
    }

    return -1;
}

int main() {
    int a[] = {2, 5, 8, 12, 15};
    int b[] = {1, 3, 7, 10, 14};

    int n = 5, m = 5, k = 5;

    printf("%d", kthSmallest(a, n, b, m, k));

    return 0;
}
