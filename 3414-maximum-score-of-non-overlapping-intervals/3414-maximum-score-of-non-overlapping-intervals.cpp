class Solution {
public:
    bool is_left_smaller_for_same_weights(vector<long long> &a, vector<long long> &b) {
        if(a[0] > b[0]) {
            return true;
        }
        if(a[0] < b[0]) return false;
        if(a.size() < b.size()) return true;
        
        sort(a.begin() + 1, a.end());
        sort(b.begin() + 1, b.end());
        return a < b;
    }

    vector<int> maximumWeight(vector<vector<int>>& intervals) {
        vector<vector<int>> sort_by_end;
        int ind = 0;
        for(auto it: intervals) {
            sort_by_end.push_back({it[1], it[0], it[2], ind ++});
        }
        sort(sort_by_end.begin(), sort_by_end.end());

        vector<vector<vector<long long>>> dp(intervals.size() + 1, vector<vector<long long>>(5, vector<long long>(1, -1)));
        for(auto it: sort_by_end) {
            // cout << it[1] << " " << it[0] << " " << it[2] << " " << it[3] << endl;
        }

        dp[0][0] = {0};

        for(int i = 0; i < ind; i ++) {
            int start = 0, end = i - 1, ans = -1;
            dp[i][0] = {0};
            dp[i + 1][0] = {0};
            while(start <= end) {
                int mid = (start + end) / 2;
                if(sort_by_end[mid][0] < sort_by_end[i][1]) {
                    ans = mid + 1;
                    start = mid + 1;
                } else {
                    end = mid - 1;
                }
            }
            
            dp[i + 1][1] = {sort_by_end[i][2], sort_by_end[i][3]};
            for(int j = 1; j <= 4; j ++) {
                if(is_left_smaller_for_same_weights(dp[i][j], dp[i + 1][j])) {
                    dp[i + 1][j] = dp[i][j];
                }
            }
            
            
            

            if(ans == -1) continue;

            // cout << i << " " << ans << endl;

            // cout << dp[ans][1][0] << endl;
            for(int j = 0; j <= 3; j ++) {
                if(dp[ans][j][0] != -1) {
                    // cout << i << " again " << ans << " " << dp[ans][j][0] << endl;
                    vector<long long> v = dp[ans][j];
                    vector<long long> av = {};
                    
                    v[0] += sort_by_end[i][2];
                    v.push_back(sort_by_end[i][3]);

                    if(is_left_smaller_for_same_weights(v, dp[i + 1][j + 1])) {
                        dp[i + 1][j + 1] = v;
                    }
                }
            }
        }
        vector<long long> ans = {0};
        for(int i = 1; i <= 4; i ++) {
            if(is_left_smaller_for_same_weights(dp[ind][i], ans)) {
                ans = dp[ind][i];
            }
        }

        vector<int> fa = {};
        for(int i = 1; i < ans.size(); i ++) {
            fa.push_back(ans[i]);
        }
        sort(fa.begin(), fa.end());
        

        
        return fa;
    }
};