class Solution {
public:
    int numDistinct(string s, string t) {
        int MOD = 1e9 + 7;
        int n = s.size(), m = t.size();
        vector<vector<int>> dp(n+1,vector<int>(m+1,0));
        for(int i = 0;i<=n;i++){
            dp[i][0] = 1;
        }
        for(int i =0;i<n;i++){
            for(int j =0;j<m;j++){
                if(s[i]==t[j]){
                    dp[i+1][j+1] = (dp[i][j] % MOD + dp[i][j+1] % MOD)% MOD;
                }
                else{
                    dp[i+1][j+1] = dp[i][j+1];
                }
            }
        }
        return dp[n][m];
    }
};