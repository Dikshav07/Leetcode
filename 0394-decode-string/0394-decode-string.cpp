class Solution {
public:
    string decodeString(string s) {
        stack<string> st;
        int n=s.size();
        for(int i=0; i<n; i++){
            if(s[i] != ']'){
                st.push(string(1, s[i]));
            }else{
                string substr ="";
                while(!st.empty() && st.top() != "["){
                    substr =st.top()+substr;
                    st.pop();
                }
                st.pop();
                string k = "";
                while(!st.empty() && isdigit(st.top()[0])){
                    k = st.top() + k;
                    st.pop();
                }
                int cnt = stoi(k);
                string decode ="";
                for(int j=0; j<cnt; j++){
                    decode += substr;
                }
                st.push(decode);
            }
        }
        string res= "";
        while(!st.empty()){
            res = st.top() + res;
            st.pop();
        }
        return res;
    }
};