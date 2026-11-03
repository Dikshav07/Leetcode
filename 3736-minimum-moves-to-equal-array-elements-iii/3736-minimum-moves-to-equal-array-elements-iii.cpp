class Solution {
public:
    int minMoves(vector<int>& nums) {
        int mx=0,sum=0;
        for(auto& it:nums)
        {
            mx=max(mx,it);
            sum+=it;
        }
        return mx*nums.size()-sum;
    }
};