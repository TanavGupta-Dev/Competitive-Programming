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
     * Compute the longest common prefix of a given list of strings
     * Ex. {"flower", "flow", "flight"}
     * Ans: "fl"
     * Explanation: Since "fl" is the longest common part at the start (prefix)
     * of all the strings.
     */
    string longestCommonPrefix(vector<string>& strs) {  
        if (strs.size() == 0) {
            return "";
        }

        // Iterate through all characters of the first string.
        // We don't need to go further since we have to find the common part of all strings.
        for (int current_char_index = 0; current_char_index < strs[0].size(); current_char_index++) {
            char current_char_to_check = strs[0][current_char_index];

            // Iterate through rest of the strings.
            for (int i = 1; i < strs.size(); i++) {

                // If the nth char of the first string != nth char of mth string,
                // or if mth string is smaller than length n, return the substring.
                if (current_char_index >= strs[i].size() || current_char_to_check != strs[i][current_char_index]) {
                    return strs[0].substr(0, current_char_index);
                }
            }
        }

        return strs[0];
    }
};

int main() {
    vector<string> strs = {"flower", "flow", "flight"};

    // prints: fl
    cout << Solution().longestCommonPrefix(strs) << endl;
}