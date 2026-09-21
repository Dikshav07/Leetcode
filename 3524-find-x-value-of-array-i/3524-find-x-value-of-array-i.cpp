class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> ans(k, 0);
        vector<long long> dp(k, 0);

        for (int num : nums) {
            vector<long long> new_dp(k, 0);
            int num_mod = num % k;
            new_dp[num_mod] += 1;

            for (int r = 0; r < k; ++r) {
                if (dp[r] > 0) {
                    int new_rem = (1LL * r * num_mod) % k;
                    new_dp[new_rem] += dp[r];
                }
            }

            for (int r = 0; r < k; ++r) {
                ans[r] += new_dp[r];
            }
            dp = std::move(new_dp);
        }

        return ans;
    }
};