class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        size_t len = nums.size();

        std::unordered_map<int,int> mapped_vector;

        for (size_t i {0ul}; i < len; i++) {
            mapped_vector[nums[i]] = i;
        }
        
        for (size_t i {0ul}; i < len; i++) {
            int diff = target - nums[i];
            if (mapped_vector.count(diff) && mapped_vector[diff] != i) {
                return {static_cast<int>(i), mapped_vector[diff]};
            }
        }
        return {};
    }
};
