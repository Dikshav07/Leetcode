class Solution {
public:
    vector<bool> pathExistenceQueries(int n, vector<int>& nums, int maxDiff, vector<vector<int>>& queries) {

        int q=queries.size();
        vector<int>dp(n);
        dp[n-1]=n-1;
        for(int i=n-2;i>=0;i--)
        {
            if(abs(nums[i+1]-nums[i])<=maxDiff) dp[i]=dp[i+1];
            else dp[i]=i;
        }
        vector<bool>ans;
        for(auto &it:queries)
        {
            int s=min(it[0],it[1]);
            int l=max(it[0],it[1]);
            if(dp[s]>=l)
            {
                ans.push_back(true);
            }
            else ans.push_back(false);
        }
        return ans;
        
    }
};