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
     * Removes a specified value from a vector by shifting all instances
     * of it to the end, keeping the rest of the elements in relative order.
     *
     * Returns the number of elements not equal to specified value.
     *
     * Ex. nums = {1, 2, 3, 3, 4, 3}, val = 3
     * Ans: nums = {1, 2, 4, 3, 3, 3}, 3
     * Explanation: There are 3 values not equal to 3 (1, 2, 4). All
     * the elements not equal to 3 have been moved to the start.
     */
    int removeElement(vector<int>& nums, int val) {
        int num_val = 0;

        for (int i = 0; i < nums.size(); i++) {
            if (nums[i] != val) {
                // `[i - num_val]` gives us the index where we have to
                // move the current element not equal to val.
                nums[i - num_val] = nums[i];
                continue;
            }

            num_val++;
        }

        return nums.size() - num_val;
    }
};

int main() {
    vector<int> nums = {1, 2, 3, 3, 4, 3};
    int val = 3;

    // prints: 3
    // prints: {1, 2, 4, 3, 3, 3}
    cout << Solution().removeElement(nums, val) << endl;
    for (int ve : nums) {
        cout << ve << " ";
    }
    cout << endl;
}