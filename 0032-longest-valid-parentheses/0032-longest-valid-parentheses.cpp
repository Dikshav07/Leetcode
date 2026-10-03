class Solution {
public:
    int longestValidParentheses(string s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '(')
                st.push(i);
            else if (st.size()) {
                s[st.top()] = s[i] = '*';
                st.pop();
            }
        }
        int curr = 0, res = 0;
        for (int i = 0; i <= s.size(); i++) {
            if (s[i] == '*')
                curr++;
            else {
                res = max(res, curr);
                curr = 0;
            }
        }
        return max(curr, res);
    }
};