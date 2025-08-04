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

// REDO
class Solution {
   public:
    /**
     * Given a sorted array of distinct integers and a target value, computes
     * the index for the target if it was inserted into the array
     * maintaining the order.
     *
     * Ex. nums = {1, 3, 5, 6}, target = 5
     * Ans: 2
     * Explanation: When we insert 5 (the target), the array becomes:
     * nums = {1, 3, 5, 5, 6}, index of target (5) => 2.
     */
    int searchInsert(vector<int>& nums, int target) {
        int low = 0, high = nums.size() - 1;

        while (low < high) {
            int mid = low + (high - low) / 2;

            // If equal to target, return the index.
            if (nums[mid] == target) {
                return mid;

                // If greater than target, then it could be as large as current index.
            } else if (nums[mid] > target) {
                high = mid;

                // If lesser than target, then it has to be atleast
                // greater than current index.
            } else {
                low = mid + 1;
            }
        }

        return nums[low] < target ? low + 1 : low;
    }
};

int main() {
    vector<int> nums = {1, 3, 5, 7};
    int target = 5;

    // prints: 2
    cout << Solution().searchInsert(nums, target) << endl;
}