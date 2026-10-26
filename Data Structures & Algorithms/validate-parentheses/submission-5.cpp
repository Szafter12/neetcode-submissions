class Solution {
public:
    bool isValid(string s) {
        if (s.length() == 0) return false;
        
        std::stack<char> parStack;
        std::unordered_map<char, char> closeToOpen = {
            {')', '('},
            {']', '['},
            {'}', '{'}
        };

        for (char c : s) {
            if (closeToOpen.count(c)) {
                if (!parStack.empty() && parStack.top() == closeToOpen[c]) {
                    parStack.pop();
                } else {
                    return false;
                }
            } else {
                parStack.push(c);
            }
        }
        return parStack.empty();
    }
};
