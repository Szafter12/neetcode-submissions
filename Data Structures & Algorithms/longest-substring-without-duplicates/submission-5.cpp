class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        size_t l {0};
        int res {0};

        std::unordered_set<char> chars;

        for (size_t p {0}; p < s.length(); p++) {
            while (chars.find(s[p]) != chars.end()) {
                chars.erase(s[l]);
                l++;
            }
            chars.insert(s[p]);
            res = std::max(res, static_cast<int>(chars.size()));
        }

        return res;
    }
};
