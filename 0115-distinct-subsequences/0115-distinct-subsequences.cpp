class Solution {
public:
    int numDistinct(string s, string t) {
        int n = s.size();
        int m = t.size();
        vector<vector<int>> pos(240);
        vector<int> dp(m+1,0);
        vector<int> dp_max(240,0);
        for(int i=0; i<m; i++) pos[t[i]].push_back(i);
        dp[0]=1;
        for(int i=0; i<n; i++)
        {
            int c = s[i];
            int end = pos[c].size();
            if(end==0) continue;
            if(dp_max[c] < end && dp[pos[c][dp_max[c]]]) dp_max[c]++;
            
            for(int j=dp_max[c]-1; j>=0; j--)
            {
                long long x = (long long) dp[pos[c][j]+1] + (long long)dp[pos[c][j]];
                if (x <= INT_MAX) dp[pos[c][j]+1] = x;
            } 

        }
        return dp[m];
    }
};