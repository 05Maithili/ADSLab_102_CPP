CIA 2 -Capstone Project: Develop and implement a solution for the 
given problem using a greedy approach.
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void findMinCoins(vector<int>& coins, int amount) {
    sort(coins.rbegin(), coins.rend()); // Sort coins in descending order
    vector<int> result;

    for (int coin : coins) {
        while (amount >= coin) {
            amount -= coin;
            result.push_back(coin);
        }
    }

    if (amount != 0) {
        cout << "Change cannot be made exactly with given denominations.\n";
        return;
    }

    cout << "Minimum coins needed: " << result.size() << "\nCoins used: ";
    for (int c : result)
        cout << c << " ";
    cout << endl;
}

int main() {
    vector<int> coins = {1, 2, 5, 10, 20, 50, 100, 500, 2000};
    int amount = 2758;

    cout << "Amount: " << amount << endl;
    findMinCoins(coins, amount);

    return 0;
}
