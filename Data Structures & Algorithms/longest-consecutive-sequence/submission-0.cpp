class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        std::set<int> numSet(nums.begin(), nums.end());

        int longestSeq = 0;
        for (int num : numSet) {
            if (!numSet.contains(num-1)) {
                int currNum = num;
                int currLongest = 1;

                while (numSet.contains(++currNum)) {
                    currLongest++;
                }

                if (currLongest > longestSeq) longestSeq = currLongest;
            }
        }

        return longestSeq;
    }
};
