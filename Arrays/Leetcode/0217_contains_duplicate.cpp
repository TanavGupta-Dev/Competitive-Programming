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
     * Checks whether the given array of numbers contains a duplicate.
     *
     * Ex. nums = {1, 2, 2}
     * Ans: true
     * Explanation: There are two instances of '2'.
     */
    bool containsDuplicate(vector<int>& nums) {
        // Track elements found using a hash set.
        unordered_set<int> found_nums;
        for (auto num : nums) {
            // If already found, then array does indeed contain duplicate.
            if (found_nums.find(num) != found_nums.end()) {
                return true;
            }

            found_nums.insert(num);
        }

        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 2};

    // prints: 1 (true)
    cout << Solution().containsDuplicate(nums) << endl;
}