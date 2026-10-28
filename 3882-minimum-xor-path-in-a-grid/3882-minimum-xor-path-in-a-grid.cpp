class Solution {
public:
    int recur(int i,int j,int val,vector<vector<int>>& grid,int m,int n,vector<vector<vector<int>>>& dp)
    {
        if(i==m-1 && j==n-1)
        {
            return val^grid[i][j];
        }
        if(~dp[i][j][val])return dp[i][j][val];
        int ans=1e9;
        if(i+1<m)ans=min(ans,recur(i+1,j,val^grid[i][j],grid,m,n,dp));
        if(j+1<n)ans=min(ans,recur(i,j+1,val^grid[i][j],grid,m,n,dp));
        return dp[i][j][val]=ans;
    }
    int minCost(vector<vector<int>>& grid) {
        int m=grid.size(),n=grid[0].size();
        vector<vector<vector<int>>>dp(m+1,vector<vector<int>>(n+1,vector<int>(1051,-1)));
        return recur(0,0,0,grid,m,n,dp);
    }
};