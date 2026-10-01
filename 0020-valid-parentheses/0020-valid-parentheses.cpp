class Solution {
public:
    bool isValid(string s) {
        stack<char> stk;
        unordered_map<char, char> bracketMap = {
            {')', '('},
            {'}', '{'},
            {']', '['}
        };
        
        for (char ch : s) {
            if (ch == '(' || ch == '{' || ch == '[') {
                stk.push(ch);
            }
            else {
                if (stk.empty() || stk.top() != bracketMap[ch]) {
                    return false;
                }
                stk.pop();
            }
        }
        return stk.empty();
    }
};
