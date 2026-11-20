class Solution {
public:
    void solve(vector<int>& nums, unordered_map<int,int>& dp, int& ans) {
        for (int x : nums) {
            dp[x + 1] = max(dp[x+1], dp[x]+1);
            dp[x] = max(dp[x], dp[x-1] + 1);

            ans = max({ans, dp[x], dp[x+1]});
        }
    }

    int maxSelectedElements(vector<int>& nums) {
        sort(nums.begin(), nums.end());

        unordered_map<int,int>dp;
        int ans=0;

        solve(nums, dp, ans);

        return ans;
    }
};