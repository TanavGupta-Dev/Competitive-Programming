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
     * Given an array of prices, where the nth element represents the price
     * of a stock at the nth day, computes the maximum profit by choosing
     * a single day to buy and then a different day in the future to sell the stock.
     *
     * Computes the maximum profit in the above mentioned scenario
     *
     * Ex. prices = {7,1,5,3,6,4}
     * Ans: 5
     * Explanation: Buy on day 2 (for 1) and then sell on day 5 (for 6),
     * yielding in a profit of 5, which is the maximum achievable.
     */
    int maxProfit(vector<int>& prices) {
        // We keep track of the maximum profit, which can be calculated for
        // every nth day by 'price of nth day - minimum price till n-1 days'
        int maximum_profit = 0;
        // For the above we also need to keep track of the minimum price till the nth day.
        int minimum_price = prices[0];
        for (int i = 1; i < prices.size(); i++) {
            if (prices[i] < minimum_price) {
                minimum_price = prices[i];
                continue;
            }

            maximum_profit = max(maximum_profit, prices[i] - minimum_price);
        }

        return maximum_profit;
    }
};

int main() {
    vector<int> prices = {7, 1, 5, 3, 6, 4};

    // prints: 5
    cout << Solution().maxProfit(prices) << endl;
}