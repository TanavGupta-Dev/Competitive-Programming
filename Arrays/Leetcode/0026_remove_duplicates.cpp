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
     * Given a sorted array of integers (may contain duplicates), return the
     * number of unique elements & shift all duplicates to the end, keeping
     * the relative order of elements the same.
     *
     * Ex. {1, 2, 2, 3, 3}
     * Ans: {1, 2, 3, 2, 3}, 3
     * Explanation: 3 unique elements, duplicates are shifted to the end.
     */
    int removeDuplicates(vector<int>& nums) {
        // The first element counts as unique.
        int num_unique_elements = 1;

        // Start from the second element
        for (int i = 1; i < nums.size(); i++) {
            // For every nth unique element we encounter (by comparing to previous)
            // `num_unique_elements++` would give us the index of where to place that unique number.
            if (nums[i] != nums[i - 1]) {
                nums[num_unique_elements++] = nums[i];
            }
        }

        return num_unique_elements;
    }
};

int main() {
    vector<int> nums = {1, 2, 2, 3, 3};

    // prints: 3
    // nums = {1, 2, 3, 3, 3}
    cout << Solution().removeDuplicates(nums) << endl;
    for (auto c : nums) {
        cout << c << ' ';
    }
}