class Solution {
public:
    string stoneGameIII(vector<int>& stoneValue) {
        int n = stoneValue.size();
        vector<long long> dp(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            long long take = 0, best = LLONG_MIN;
            for (int k = 0; k < 3 && i + k < n; ++k) {
                take += stoneValue[i + k];
                best = max(best, take - dp[i + k + 1]);
            }
            dp[i] = best;
        }
        if (dp[0] > 0) return "Alice";
        if (dp[0] < 0) return "Bob";
        return "Tie";
    }
};