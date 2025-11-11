#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

// Function to check if all tasks can be finished within D days with given work/day
bool canFinish(vector<int>& task, int D, int workPerDay) {
    int daysNeeded = 0;
    for (int t : task) {
        // Divide task work by allowed work per day
        daysNeeded += (t + workPerDay - 1) / workPerDay; // ceil division
        if (daysNeeded > D)
            return false;
    }
    return true;
}

// Function to find minimum work per day
int minWorkPerDay(vector<int>& task, int D) {
    int low = 1;                            // Minimum work/day
    int high = *max_element(task.begin(), task.end());  // Max possible (worst case)
    int ans = high;

    while (low <= high) {
        int mid = (low + high) / 2;
        if (canFinish(task, D, mid)) {
            ans = mid;        // Possible to finish, try smaller
            high = mid - 1;
        } else {
            low = mid + 1;    // Too small, need more work per day
        }
    }

    return ans;
}

int main() {
    vector<int> task = {30, 11, 23, 4, 20};
    int D = 6;

    cout << "Minimum work per day to finish tasks in " << D << " days: "
         << minWorkPerDay(task, D) << endl;

    return 0;
}
