class Solution {
public:
    int distinctSubseqII(string s) {
        int n=s.size();
        int mod=(int)(1e9+7);
        unordered_map<char,int>m;
        vector<long long int>dp(n+1,0);
        dp[0]=1;
        for(int i=1;i<dp.size();i++){
            dp[i]=(2*(dp[i-1]))%mod;
            char ch=s[i-1];
            if(m.count(ch)!=0) {
                int j=m[ch]-1;
                dp[i]=(dp[i]-dp[j])%mod;
            }
            m[ch]=i;
        }
        long long p=((dp[n])-1)%mod;
        return p<0?p+mod:p;
    }
};