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
     * Given a sorted array, return the 2 indices of elements which add
     * up to a given target value. Input may only contain 1 solution.
     *
     * Ex. nums = {2,7,11,15}, target = 9
     * Ans: {0,1}
     * Explanation: since element at 0 (2) and 1 (7) add up to be 9
     */
    vector<int> twoSum(vector<int> &nums, int target) {
        unordered_map<int, int> num_to_index = {};

        for (int i = 0; i < nums.size(); i++) {
            int current_num = nums[i];

            if (num_to_index.find(current_num) != num_to_index.end()) {
                return {num_to_index[current_num], i};
            }
            num_to_index[target - current_num] = i;
        }

        return {};
    }
};

int main() {
    vector<int> nums = {3, 2, 4};
    int target = 6;

    vector<int> result = Solution().twoSum(nums, target);

    // prints: {1, 2}
    for (int index : result) {
        cout << index << " ";
    }
    cout << endl;
}