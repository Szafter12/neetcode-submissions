class Solution {
public:
    bool isPalindrome(string s) {
        int start = 0;
        int end = s.length() - 1;

        while (start < end) {
            while (start < end && !alphaNum(s[start])) start++;
            while (end > start && !alphaNum(s[end])) end--;

            if (tolower(s[start]) != tolower(s[end])) return false;
            start++;
            end--;
        }

        return true;
    }
private:
    bool alphaNum(char c) {
        return (c >= 'A' && c <= 'Z' ||
                c >= 'a' && c <= 'z' ||
                c >= '0' && c <= '9');
    }
};
