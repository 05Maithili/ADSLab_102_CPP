#include <iostream>
using namespace std;

int coins[50];   // to store coins (assuming max 50 types)
int n, sum;
int ways = 0;
int comb[50];    // to store one combination

void findWays(int index, int currentSum, int start) {
    if (currentSum == sum) {
        // Print one valid combination
        cout << "Way " << ++ways << ": ";
        for (int i = 0; i < index; i++)
            cout << comb[i] << " ";
        cout << endl;
        return;
    }

    if (currentSum > sum) return; // stop if sum exceeds

    // Try all coins (starting from 'start' to avoid duplicate orders)
    for (int i = start; i < n; i++) {
        comb[index] = coins[i];
        findWays(index + 1, currentSum + coins[i], i); // i (not i+1) because same coin can repeat
    }
}

int main() {
    cout << "Enter number of coin types: ";
    cin >> n;

    cout << "Enter coin denominations: ";
    for (int i = 0; i < n; i++)
        cin >> coins[i];

    cout << "Enter total sum: ";
    cin >> sum;

    cout << "\nAll possible combinations:\n";
    findWays(0, 0, 0);

    cout << "\nTotal number of ways = " << ways << endl;

    return 0;
}
