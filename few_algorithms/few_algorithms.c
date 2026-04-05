#include "few_algorithms.h"

int BinarySearch(const int arr[], int x, int n) {
    int mid, high, low;
    high = n - 1;
    low = 0;

    while (low <= high) {
        mid = (low + high) / 2;
        if (x > arr[mid]) {
            low = mid + 1;
        } else if (x < arr[mid]) {
            high = mid - 1;
        } else {
            return mid;
        }
    }
    return -1;
}

int gcd(int m, int n) {
    while (n > 0) {
        int rem = m % n;
        m = n;
        n = rem;
    }
    return m;
}

long int pow(long int x, long int n) {
    if (n == 0) {
        return 1;
    }
    if (n % 2 == 0) {
        return pow(x * x, n / 2);
    } else {
        return pow(x * x, n / 2) * x;
    }
}

long long pow2(long long base, long long exp) {
    long long res = 1;
    while (exp > 0) {
        if (exp % 2 == 1) {
            res *= base;
        }
        base *= base;
        exp /= 2;
    }
    return res;
}