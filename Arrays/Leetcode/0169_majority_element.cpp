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
     * Given an array of integers of size n, where a specific element
     * appears more than n/2 times (the majority), we have to return
     * that element.
     *
     * Ex. nums = {2,2,1,1,1,2,2}
     * Ans: 2
     * Explanation: 2 appears four times, which makes it the majority.
     */
    int majorityElement(vector<int>& nums) {
        // Moore's Voting Algorithm:
        // Maintain a candidate and a vote count.
        // Increase vote if current element matches the candidate.
        // Otherwise, decrease vote. If vote becomes 0, switch candidate.
        int majority_element = nums[0];
        int votes = 1;
        for (int i = 1; i < nums.size(); i++) {
            if (nums[i] == majority_element) {
                votes++;
                continue;
            }

            votes--;
            if (votes == 0) {
                majority_element = nums[i];
                votes = 1;
            }
        }

        return majority_element;
    }
};

int main() {
    vector<int> nums = {2, 2, 1, 1, 1, 2, 2};

    // prints: 2
    cout << Solution().majorityElement(nums) << endl;
}