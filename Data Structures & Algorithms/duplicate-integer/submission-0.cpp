class Solution {
public:
    bool hasDuplicate(vector<int>& nums) {
        std::unordered_map<int,int> appears;
        size_t len = nums.size();

        for (size_t i {0}; i < len; i++) {
            if (appears.contains(nums[i])) { 
                return true;
            } else {
                appears[nums[i]] = 1;
            }
        }

        return false;
    }
};