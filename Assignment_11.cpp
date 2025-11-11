#include <iostream>
#include <cctype>
using namespace std;

bool canTransform(string s1, string s2) {
    int i = 0, j = 0;

    while (i < s1.size() && j < s2.size()) {
        if (toupper(s1[i]) == s2[j]) {  // Match after making uppercase
            i++;
            j++;
        } 
        else if (islower(s1[i])) {  // Delete lowercase
            i++;
        } 
        else {  // Uppercase mismatch
            return false;
        }
    }

    // Delete remaining lowercase letters in s1
    while (i < s1.size()) {
        if (isupper(s1[i]))
            return false;
        i++;
    }

    // If all characters in s2 are matched
    return j == s2.size();
}

int main() {
    string s1 = "daBcd";
    string s2 = "ABC";

    if (canTransform(s1, s2))
        cout << "Yes, transformation is possible.";
    else
        cout << "No, transformation is not possible.";

    return 0;
}
