class Solution {
public:
    //T.C : O(n^3 * div(n) + n^2 * k) ~ O(n^3)
    
    int getMinCost(string s, int start, int end) {
        int len = end - start + 1;
        
        int minCost = 1e9;
        for(int d = 1; d < len; d++)
        {
            if(len % d != 0)
            continue;

            int cost = 0;
            for(int group = 0; group < d; group++)
            {
                int l = start + group;
                int r = l + (len/d - 1) * d;

                while(l < r)
                {
                    if(s[l] != s[r])
                    cost++;

                    l += d;
                    r -= d;
                }
            }

            minCost = min(minCost, cost);
        }

        return minCost;
    }

    int minimumChanges(string s, int k) {
        int n = s.length();

        vector<vector<int>> costMemo(n, vector<int>(n, 1e9));
        for(int i = 0; i < n; i++)
        {
            for(int j = i+1; j < n; j++)
            {
                costMemo[i][j] = getMinCost(s, i, j);
            }
        }
        //on a serious note bruh
        vector<vector<int>> dp(n+1, vector<int>(k+1, 1e9));
        dp[n][0] = 0;

        for(int start = n; start >= 0; start--)
        {
            for(int pieces = 1; pieces <= k; pieces++)
            {
                if(start + 2*pieces > n)
                continue;

                for(int end = start + 1; end < n; end++)
                {
                    int cost = costMemo[start][end];
                    int remainingCost = dp[end+1][pieces-1];

                    dp[start][pieces] = min(dp[start][pieces], cost + remainingCost);
                }
            }
        }

        return dp[0][k];
    }
};