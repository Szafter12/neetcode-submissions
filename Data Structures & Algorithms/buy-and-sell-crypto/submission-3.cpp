class Solution {
public:
    int maxProfit(vector<int>& prices) {
        size_t left {0};
        size_t right {1};
        int maxProfit {0};

        while (right < prices.size()) {
            if (prices[left] < prices[right]) {
                int diff = prices[right] - prices[left];
                maxProfit = std::max(maxProfit, diff);
            } else {
                left = right;
            }
            right++;
        }

        return maxProfit;
    }
};
