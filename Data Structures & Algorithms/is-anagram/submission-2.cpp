class Solution {
public:
    bool isAnagram(string s, string t) {
        if (s.length() != t.length()) return false;
        
        std::sort(s.begin(), s.end());
        std::sort(t.begin(), t.end());
        size_t len = s.length();

        for (size_t i {0ul}; i < len; i++) {
            if (s[i] != t[i]) return false;
        }

        return true;
    }
};
