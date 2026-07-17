class Solution {
public:
    vector<int> gcdValues(vector<int>& nums, vector<long long>& queries) {
        int mx = *max_element(nums.begin(), nums.end());
        vector<int> cnt(mx + 1);
        for (int x : nums) cnt[x]++;
        vector<long long> gcdCnt(mx + 1);
        for (int g = mx; g >= 1; --g) {
            long long c = 0;
            for (int j = g; j <= mx; j += g)
                c += cnt[j];

            gcdCnt[g] = c * (c - 1) / 2;

            for (int j = g + g; j <= mx; j += g)
                gcdCnt[g] -= gcdCnt[j];
        }
        for (int i = 2; i <= mx; i++)
            gcdCnt[i] += gcdCnt[i - 1];

        vector<int> ans;
        for (long long q : queries){
        
            ans.push_back(lower_bound(gcdCnt.begin() + 1, gcdCnt.end(), q + 1) - gcdCnt.begin());
        
        }
        
        return ans;
    }
};










