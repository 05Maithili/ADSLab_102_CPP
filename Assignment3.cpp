#include <iostream>
using namespace std;

/*
Mathematical Explanation:
To find trailing zeroes in n!, count how many times 5 divides it:
    n/5 + n/25 + n/125 + ...
This tells how many 10s are there (and hence trailing zeroes).
We use binary search to find the smallest number whose factorial has at least n trailing zeroes.
*/

int countTrailingZeroes(int x) {
    int count = 0;
    while (x > 0) {
        count += x / 5;
        x /= 5;
    }
    return count;
}

int findSmallestWithTrailingZeroes(int n) {
    int low = 0, high = 5 * n;
    int ans = -1;

    while (low <= high) {
        int mid = (low + high) / 2;
        int zeroes = countTrailingZeroes(mid);

        if (zeroes >= n) {
            ans = mid;
            high = mid - 1; // Try smaller number
        } else {
            low = mid + 1;  // Try bigger number
        }
    }

    return ans;
}

int main() {
    int n;
    cout << "Enter number of trailing zeroes required: ";
    cin >> n;

    int result = findSmallestWithTrailingZeroes(n);
    cout << "Smallest number whose factorial has at least " << n << " trailing zeroes is: " << result << endl;

    return 0;
}
