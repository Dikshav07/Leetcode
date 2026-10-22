class Solution{
public:
    int minOperations(vector<int>& nums) {
        int n=nums.size(),idx=-1;
        for(int i=1;i<n;++i)
        {
            if(nums[i]-nums[i-1]!=1)
            {
                if(~idx)
                {
                    idx=-2;
                    break;
                }
                idx=i;
            }
        }
        if(idx==-1)return 0;
        if(idx!=-2)return min(idx,n-idx+2);
        idx=-1;
        reverse(nums.begin(),nums.end());
        for(int i=1;i<n;++i)
        {
            if(nums[i]-nums[i-1]!=1)
            {
                if(~idx)return -1;
                idx=i;
            }
        }
        if(idx==-1)return 1;
        return 1+min(idx,n-idx);
    }
};