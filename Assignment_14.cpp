#include <iostream>
#include <vector>
using namespace std;

void findSubsets(int arr[], int n, int index, int sum, int target, vector<int>& current) {
    // Base case: if sum equals target
    if (sum == target) {
        cout << "{ ";
        for (int x : current)
            cout << x << " ";
        cout << "}\n";
        return;
    }

    // If all elements are processed or sum exceeds target
    if (index == n || sum > target)
        return;

    // Include current element
    current.push_back(arr[index]);
    findSubsets(arr, n, index + 1, sum + arr[index], target, current);

    // Exclude current element (Backtrack)
    current.pop_back();
    findSubsets(arr, n, index + 1, sum, target, current);
}

int main() {
    int arr[] = {2, 3, 5, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;
    vector<int> current;

    cout << "Subsets with sum " << target << " are:\n";
    findSubsets(arr, n, 0, 0, target, current);

    return 0;
}
