class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int min_val = prices[0];
        int max_diff = 0;

        for (int p : prices) {
            min_val = std::min(min_val, p);
            max_diff = std::max(max_diff, p - min_val);
        }

        return max_diff;
    }
};
