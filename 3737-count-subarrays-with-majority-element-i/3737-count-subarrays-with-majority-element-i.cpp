class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        vector<int> mp(n);
        for(int i = 0; i < n; i++) {
            if(nums[i] == target)
                mp[i] = 1;
            else
                mp[i] = -1;
        }
        vector<int> prefix(n + 1, 0);
        for(int i = 0; i < n; i++) {
            prefix[i + 1] = prefix[i] + mp[i];
        }
        long long cnt = 0;
        for(int l=0; l < n; l++) {
            for(int r = l; r < n; r++) {
                int sum = prefix[r + 1] - prefix[l];
                if(sum>0)
                    cnt++;
            }
        }


        return cnt;
    }
};