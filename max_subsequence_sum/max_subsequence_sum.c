#include "max_subsequence_sum.h"
static int Max_Three(int a, int b, int c);

int MaxSubSequenceSum1(const int arr[], int n) {
    int max_sum = 0;
    for (int i = 0; i < n; ++i) {
        for (int j = i; j < n; ++j) {
            int this_sum = 0;
            for (int k = i; k <= j; ++k) {
                this_sum += arr[k];
            }

            if (this_sum > max_sum) {
                max_sum = this_sum;
            }
        }
    }
    return max_sum;
}

int MaxSubSequenceSum2(const int arr[], int n) {
    int max_sum = 0;
    for (int i = 0; i < n; ++i) {
        int this_sum = 0;
        for (int j = i; j < n; ++j) {
            this_sum += arr[j];

            if (this_sum > max_sum) {
                max_sum = this_sum;
            }
        }
    }
    return max_sum;
}

int MaxSubSequenceSum3(const int arr[], int left, int right) {
    if (left == right) {
        if (arr[left] > 0) {
            return arr[left];
        }
        return 0;
    }

    int center = (left + right) / 2;
    int max_left_sum = MaxSubSequenceSum3(arr, left, center);
    int max_right_sum = MaxSubSequenceSum3(arr, center + 1, right);

    int max_left_border_sum = 0;
    int left_border_sum = 0;
    for (int i = center; i >= left; --i) {
        left_border_sum += arr[i];
        if (left_border_sum > max_left_border_sum) {
            max_left_border_sum = left_border_sum;
        }
    }

    int max_right_border_sum = 0;
    int right_border_sum = 0;
    for (int i = center + 1; i <= right; ++i) {
        right_border_sum += arr[i];
        if (right_border_sum > max_right_border_sum) {
            max_right_border_sum = right_border_sum;
        }
    }

    return Max_Three(max_left_sum, max_right_sum, max_right_border_sum + max_left_border_sum);
}

static int Max_Three(int a, int b, int c) {
    return a > b ? (a > c ? a : c) : (b > c ? b : c);
}

int MaxSubSequenceSum4(const int arr[], int n) {
    int this_sum, max_sum;
    this_sum = max_sum = 0;

    for (int i = 0; i < n; ++i) {
        this_sum += arr[i];

        if (this_sum > max_sum) {
            max_sum = this_sum;
        } else if (this_sum < 0) {
            this_sum = 0;
        }
    }

    return  max_sum;
}