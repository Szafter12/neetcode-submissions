class Solution {
public:
    vector<int> topKFrequent(vector<int> &nums, int k) {
        std::unordered_map<int, int> numSet;
        std::vector<int> res(k);
        std::vector<std::vector<int>> freq(nums.size() + 1);

        for (int i {0}; i < nums.size(); i++) {
            if (numSet.contains(nums[i])) {
                numSet[nums[i]]++;
            } else {
                numSet[nums[i]] = 1;
            }
        }

        for (auto &[key, value] : numSet) {
            freq[value].push_back(key);
        }

        for (int i = freq.size() - 1; i >= 0; i--) {
           for (int n : freq[i]) {
                res[--k] = n;

                if (k == 0) return res;
           }
        }

        return {};
    }
};
