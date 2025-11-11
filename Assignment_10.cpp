#include <iostream>
using namespace std;

bool isSubsetSum(int arr[], int n, int sum) {
    bool subset[n + 1][sum + 1];

    // Initialize the first column as true (sum = 0 can always be achieved with empty subset)
    for (int i = 0; i <= n; i++)
        subset[i][0] = true;

    // Initialize the first row (except subset[0][0]) as false
    for (int j = 1; j <= sum; j++)
        subset[0][j] = false;

    // Fill the subset table
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= sum; j++) {
            if (arr[i - 1] <= j)
                subset[i][j] = subset[i - 1][j - arr[i - 1]] || subset[i - 1][j];
            else
                subset[i][j] = subset[i - 1][j];
        }
    }

    return subset[n][sum];
}

int main() {
    int arr[] = {3, 34, 4, 12, 5, 2};
    int sum = 9;
    int n = sizeof(arr) / sizeof(arr[0]);

    if (isSubsetSum(arr, n, sum))
        cout << "Subset with given sum exists.";
    else
        cout << "No subset with given sum.";

    return 0;
}
