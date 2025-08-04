#include <algorithm>
#include <cmath>
#include <deque>
#include <functional>
#include <iostream>
#include <limits>
#include <map>
#include <numeric>
#include <queue>
#include <set>
#include <stack>
#include <string>
#include <unordered_map>
#include <unordered_set>
#include <vector>

using namespace std;

class Solution {
   public:
    /**
     * Given an array of digits (numbers from 1-9), representing a possibly large number,
     * without any leading zeros (No testcase will have {0, ..}).
     * We have to 'add 1' to the number and return the resultant vector.
     *
     * Ex. digits = {1, 2, 3}
     * Ans: result = {1, 2, 4}
     * Explanation: digits vector = {1, 2, 3},
     * So, input number = 123, add 1 => 124
     * So, result = {1, 2, 4}.
     */
    vector<int> plusOne(vector<int>& digits) {
        vector<int> result;

        // Keep track of the carry.
        int carry = 0;
        for (int i = digits.size() - 1; i >= 0; i--) {
            // We have the ternary condition here to add the 1 mentioned in the question
            // to the least significant (last) digit.
            int sum = digits[i] + (i == digits.size() - 1 ? 1 : 0) + carry;

            // `sum % 10` gives us the result digit for this index.
            result.push_back(sum % 10);

            carry = sum / 10;
        }

        // Add leftover carry (for cases like {9,9..})
        if (carry) {
            result.push_back(1);
        }

        // Reverse since we used `push_back()`.
        reverse(result.begin(), result.end());

        return result;
    }
};

int main() {
    vector<int> digits = {9, 9, 9};
    vector<int> result = Solution().plusOne(digits);

    // prints: 1 0 0 0
    for (auto ve : result) {
        cout << ve << " ";
    }
}