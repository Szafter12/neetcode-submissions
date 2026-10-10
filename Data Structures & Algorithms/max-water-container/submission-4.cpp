class Solution {
public:
    int maxArea(vector<int>& heights) {
        int maxArea {0};
        int start {0};
        int end = heights.size() - 1;

        while (start < end) {
            int width = end - start;
            int height = std::min(heights[start], heights[end]);
            int currentArea = width * height;
            if (currentArea > maxArea) {
                maxArea = currentArea;
            }

            if (heights[start] > heights[end]) {
                end--;
            } else {
                start++;
            }
        }

        return maxArea;

    }
};
