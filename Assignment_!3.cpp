#include <iostream>
#include <vector>
#include <set>
using namespace std;

void findSubsets(vector<int>& arr) {
    int n = arr.size();
    set<vector<int>> uniqueSubsets;  // To store only distinct subsets

    int total = 1 << n;  // 2^n possible subsets

    for (int mask = 0; mask < total; mask++) {
        vector<int> subset;
        for (int i = 0; i < n; i++) {
            if (mask & (1 << i))  // if i-th bit is set
                subset.push_back(arr[i]);
        }
        uniqueSubsets.insert(subset);  // Automatically removes duplicates
    }

    // Print all unique subsets
    cout << "All distinct subsets:\n";
    for (auto subset : uniqueSubsets) {
        cout << "{ ";
        for (int x : subset)
            cout << x << " ";
        cout << "}\n";
    }
}

int main() {
    vector<int> arr = {1, 2, 2};
    findSubsets(arr);
    return 0;
}
