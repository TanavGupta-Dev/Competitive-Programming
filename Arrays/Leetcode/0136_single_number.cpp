#include <algorithm>
#include <cmath>
#include <cstdint>
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
     * Returns the unique element in a non-empty array
     * of elements where there are 2 instances of all elements
     * except one.
     *
     * Ex. nums = {2, 2, 1}
     * Ans: 1
     * Explanation: 1 is present only one time & is unique.
     */
    int singleNumber(vector<int>& nums) {
        // XOR of a number with itself is 0, and with 0 is the number itself.
        // So all duplicate numbers cancel out, leaving the unique one.
        int result = 0;
        for (auto num : nums) {
            result ^= num;
        }
        return result;
    }
};

int main() {
    vector<int> nums = {2, 2, 1};

    // prints: 1
    cout << Solution().singleNumber(nums) << endl;
}