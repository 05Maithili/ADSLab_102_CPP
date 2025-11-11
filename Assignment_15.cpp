#include <iostream>
#include <vector>
#include <queue>
using namespace std;

struct Node {
    int level;      // index of element
    int sum;        // current subset sum
    vector<int> subset; // current subset
};

// Function to solve Subset Sum using Branch and Bound
void subsetSumBranchBound(int arr[], int n, int target) {
    queue<Node> q;

    // Start with root node (level = -1, sum = 0)
    Node root = {-1, 0, {}};
    q.push(root);

    cout << "Subsets with sum " << target << " are:\n";

    while (!q.empty()) {
        Node current = q.front();
        q.pop();

        // Next level node
        int level = current.level + 1;

        if (level < n) {
            // Include current element
            Node include = current;
            include.level = level;
            include.sum += arr[level];
            include.subset.push_back(arr[level]);

            // If subset sum equals target → print it
            if (include.sum == target) {
                cout << "{ ";
                for (int x : include.subset) cout << x << " ";
                cout << "}\n";
            }
            // Bound condition: if sum < target, explore further
            if (include.sum < target)
                q.push(include);

            // Exclude current element
            Node exclude = current;
            exclude.level = level;
            q.push(exclude);
        }
    }
}

int main() {
    int arr[] = {2, 3, 5, 6, 8, 10};
    int n = sizeof(arr) / sizeof(arr[0]);
    int target = 10;

    subsetSumBranchBound(arr, n, target);
    return 0;
}
