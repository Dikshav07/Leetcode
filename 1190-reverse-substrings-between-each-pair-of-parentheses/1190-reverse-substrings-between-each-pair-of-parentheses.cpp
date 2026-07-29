class Solution {
public:
    string reverseParentheses(string s) {
        stack<int> st;

        for(int i = 0;i<s.size();i++){

            if(s[i]=='('){
                st.push(i); 
            }
            if(s[i]==')'){
                reverse(s.begin()+st.top(),s.begin()+i);
                st.pop();
            }
            
        }
        string ans;
        for(auto x:s){
            if(x!='('&&x!=')')
                ans+=x;
        }

        return ans;
    }
};