class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int size = nums.size();

        vector<int> prefix(size);
        vector<int> postfix(size);
        vector<int> output(size);

        prefix[0] = nums[0];
        for (int i{1}; i < size; i++) {
            prefix[i] = prefix[i-1] * nums[i];
        }

        postfix[size-1] = nums[size-1];
        for (int i{size-2}; i >= 1; i--) {
            postfix[i] = postfix[i + 1] * nums[i];
        }

        for (int i{0}; i < size; i++) {
            if (i == 0) {
                output[i] = postfix[i+1];
                continue;
            }

            if (i == (size - 1)) {
                output[i] = prefix[i-1];
                continue;
            }

            output[i] = prefix[i-1] * postfix[i+1];
        }

        return output;
    }
};
