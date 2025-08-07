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
     * Given the array of integers, returns whether there exists two distinct indices i & j
     * where nums[i] == nums[j] & abs(i - j) <= k.
     *
     * Ex. nums = {1,2,3,1}, k = 3
     * Ans: true
     * Explanation: index 0 & 3 have the same element and abs(0 - 3) = 3 <= 3 (k).
     */
    bool containsNearbyDuplicate(vector<int>& nums, int k) {
        // Use a hash set to keep track of elements found
        // in a window of size `k + 1`.
        unordered_set<int> window_found;
        for (int i = 0; i < nums.size(); i++) {
            // If element is outside of window start index, remove it.
            if (i > k) {
                window_found.erase(nums[i - k - 1]);
            }

            if (window_found.count(nums[i])) {
                return true;
            }

            window_found.insert(nums[i]);
        }

        return false;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 1};
    int k = 3;

    // prints: 1 (true)
    cout << Solution().containsNearbyDuplicate(nums, k) << endl;
}