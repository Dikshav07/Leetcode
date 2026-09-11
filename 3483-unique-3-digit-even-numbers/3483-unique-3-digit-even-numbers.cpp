class Solution {
public:
    int totalNumbers(vector<int>& digits) {
        int n=digits.size();
        int cnte=0;
        set<string> st;

        for(int i=0;i<n;i++){
            if(digits[i]==0) continue;

            for(int j=0;j<n;j++){
                if(j==i) continue;

                for(int k=0;k<n;k++){

                    if(k==j || k==i || digits[k]%2 ==1) continue;

                    string ans="";
                    ans+=to_string(digits[i]);
                    ans+=to_string(digits[j]);
                    ans+=to_string(digits[k]);

                    st.insert(ans);
                }
            }
        }

        return st.size();

    }
};