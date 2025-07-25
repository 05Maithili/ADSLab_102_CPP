/*
------------------------------------------------------------
Mathematical Explanation:

Let the array be sorted such that all 0s come before all 1s.
For example: [0, 0, 0, 1, 1, 1]

Let 'n' be the size of the array.

We want to count the number of 1s in the array.

We apply binary search to find the **first occurrence of 1**.

- If a[mid] == 0:
    Then all elements before or at 'mid' are 0 → move right (low = mid + 1)
    
- If a[mid] == 1:
    Check if it is the **first 1**:
        - If (mid == 0) or (a[mid - 1] == 0): then it is the first 1.
        - Otherwise, move left (high = mid - 1)

Once we find the first 1 at index 'k',
    Number of 1s = n - k

Time Complexity: O(log n)
------------------------------------------------------------
*/



#include <iostream>
using namespace std;

int main() {
    int i, a[10], n;
    cout << "Enter size of array (max 10): ";
    cin >> n;

    // Input validation for size
    if (n < 1 || n > 10) {
        cout << "Invalid size. Please enter a size between 1 and 10." << endl;
        return 1;
    }

    cout << "Enter elements of array (only 0s and 1s): ";
    for (i = 0; i < n; i++) {
        cin >> a[i];
        // Corrected condition to check for valid input
        if (a[i] != 0 && a[i] != 1) {
            cout << "Invalid input. Please enter only 0s and 1s." << endl;
            return 1;
        }
    }

    int low = 0;
    int high = n - 1;
    int mid;

    // Binary search to find the number of 1s
    while (low <= high) {
        mid = (low + high) / 2;
        if (a[mid] == 1) {
            // Check if it's the last 1
            if (mid == n - 1 || a[mid + 1] == 0) {
                cout << "Number of 1s: " << n - mid - 1 << endl;
                break;
            } else {
                low = mid + 1;
            }
        } else { // a[mid] == 0
            // Check if it's the first 0
            if (mid == 0 || a[mid - 1] == 1) {
                cout << "Number of 1s: " << n - mid << endl;
                break;
            } else {
                high = mid - 1;
            }
        }
    }

    // If the loop ends without finding a 1
    if (low > high) {
        cout << "Number of 1s: 0" << endl;
    }

    return 0;
}



