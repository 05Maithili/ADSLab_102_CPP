#include <iostream>
using namespace std;

/*
Mathematical Explanation:
Using Divide and Conquer, we:
- Divide the array into halves.
- Recursively move zeros in each half.
- In merge step, collect non-zero elements first, then zeroes.
*/

void mergeZeroes(int arr[], int left, int mid, int right) {
    int temp[100];  // temporary array (sufficiently large)
    int idx = 0;

    // Collect non-zero elements from left half
    for (int i = left; i <= mid; i++) {
        if (arr[i] != 0)
            temp[idx++] = arr[i];
    }

    // Collect non-zero elements from right half
    for (int i = mid + 1; i <= right; i++) {
        if (arr[i] != 0)
            temp[idx++] = arr[i];
    }

    // Count total elements
    int total = right - left + 1;

    // Fill non-zero elements back
    for (int i = 0; i < idx; i++) {
        arr[left + i] = temp[i];
    }

    // Fill remaining with zeroes
    for (int i = idx; i < total; i++) {
        arr[left + i] = 0;
    }
}

void moveZeroesDC(int arr[], int left, int right) {
    if (left >= right) return;

    int mid = (left + right) / 2;
    moveZeroesDC(arr, left, mid);
    moveZeroesDC(arr, mid + 1, right);
    mergeZeroes(arr, left, mid, right);
}

int main() {
    int arr[100], n;
    cout << "Enter size of array: ";
    cin >> n;

    cout << "Enter array elements (0s and non-zeros): ";
    for (int i = 0; i < n; i++)
        cin >> arr[i];

    moveZeroesDC(arr, 0, n - 1);

    cout << "Array after moving zeroes to end: ";
    for (int i = 0; i < n; i++)
        cout << arr[i] << " ";

    return 0;
}
