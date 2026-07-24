class Solution {
public:
    int solve (vector<int>& nums){
        int n = nums.size();
        if (n == 1)
            return 1;
        if (n == 2)
            return 2;
        int ans = ceil(log2(n + 1));
        return 1 << ans;
    }
    int uniqueXorTriplets(vector<int>& nums) {
        return solve(nums);
    }
};