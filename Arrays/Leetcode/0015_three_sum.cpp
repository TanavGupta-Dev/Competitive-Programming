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

// TODO

class Solution {
   public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        unordered_map<int, int> index_map = {};

        for (int i = 0; i < nums.size(); i++) {
            index_map[nums[i]] = i;
        }

        vector<vector<int>> triplets;
        for (int i = 0; i < nums.size(); i++) {
            for (int j = i + 1; j < nums.size(); j++) {
                int first = nums[i];
                int second = nums[j];
                int target = -(first + second);

                if (index_map.find(target) == index_map.end()) {
                    continue;
                }

                triplets.push_back({first, second, target});
                index_map.erase(target);
            }
        }

        return triplets;
    }
};

int main() {
    // -4, -1, -1, 0, 1, 2
    vector<int> nums = {-1, 0, 1, 2, -1, -4};

    vector<vector<int>> result = Solution().threeSum(nums);
    for (auto v : result) {
        for (auto ve : v) {
            cout << ve << " ";
        }
        cout << endl;
    }
}