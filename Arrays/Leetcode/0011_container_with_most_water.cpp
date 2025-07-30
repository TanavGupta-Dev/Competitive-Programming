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
     * Compute the maximum area of any container, given a set of walls.
     * with heights, area = distance * min(h1, h2), distance is difference of index
     * between 2 walls.
     *
     * Ex. {1,8,6,2,5,4,8,3,7}
     * Ans: 49
     * Explanation: The 2nd and last walls (8, 7)
     * min(8, 7) * 7 = 49, which is the maximum achievable area.
     */
    int maxArea(vector<int>& height) {
        int left_index = 0, right_index = height.size() - 1;
        int maxArea = 0;

        // Use a two pointer approach, keep track of left and right indices.
        while (left_index < right_index) {
            int left_height = height[left_index];
            int right_height = height[right_index];

            maxArea = max(maxArea, (right_index - left_index) * min(left_height, right_height));

            // We can only move 1 of the 2 pointers to their next spot.
            // We have to move the pointer that points to the smaller height,
            // as moving the one with the taller height may prevent us from achieving the max later on.
            if (left_height < right_height) {
                left_index += 1;
            } else {
                right_index -= 1;
            }
        }

        return maxArea;
    }
};

int main() {
    vector<int> height = {1, 8, 6, 2, 5, 4, 8, 3, 7};

    // prints: 49
    cout << Solution().maxArea(height) << endl;
}