class Solution {
public:
    bool isValid(string s) {
        stack<char>st;
        for(char it : s){
            if(st.empty() || it == '(' || it == '{' || it == '[' ){
                st.push(it);
                continue;
            } 
            if(it == ')' && st.top() == '('){
                st.pop();
                continue;
            } 
            else if(it == '}' && st.top() == '{'){
                st.pop();
                continue;
            }
            else if(it == ']' && st.top() == '['){
                st.pop();
                continue;
            }
            else {
                return false;
            }
            
        }
        return st.empty();
    }
};