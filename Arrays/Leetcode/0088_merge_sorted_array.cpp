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

// REDO
// NOTE: Do not shift the elements of nums1 to the end.
class Solution {
   public:
    /**
     * Given 2 sorted arrays, nums1 & nums2, merges both the arrays
     * into another sorted array using their elements.
     * It is also given the sizes m & n of the arrays respectively & nums1
     * has extra space of n elements allocated so the resultant array may fit in it.
     *
     * Ex. nums1 = {1,2,3,0,0,0}, m = 3, nums2 = {2,5,6}, n = 3
     * Ans: nums1 = {1,2,2,3,5,6}
     * Explanation: When we combine all the elements from
     * nums1 & nums2 and sort them either in place of nums1 or replace
     * each element of nums1, we get the aforementioned array.
     */
    void merge(vector<int>& nums1, int m, vector<int>& nums2, int n) {
        // Shift the elements of nums1 to the end
        // (or by n spaces, same thing.)
        for (int i = m + n - 1; i >= n; i--) {
            nums1[i] = nums1[i - n];
        }

        // Initialize the 2 pointers.
        int p1 = n, p2 = 0;
        int current_index = 0;

        while (current_index < m + n) {
            // We use INT MAX so that we may always get the
            // other number during comparision.
            int first = p1 < m + n ? nums1[p1] : INT32_MAX;
            int second = p2 < n ? nums2[p2] : INT32_MAX;

            // Assign the smaller number to current index and move its pointer.
            if (first <= second) {
                nums1[current_index++] = first;
                p1++;
            } else {
                nums1[current_index++] = second;
                p2++;
            }
        }
    }
};

int main() {
    vector<int> nums1 = {1, 2, 3, 0, 0, 0};
    vector<int> nums2 = {2, 5, 6};

    Solution().merge(nums1, 3, nums2, nums2.size());

    // prints: 1 2 2 3 5 6
    for (auto ve : nums1) {
        cout << ve << " ";
    }
}