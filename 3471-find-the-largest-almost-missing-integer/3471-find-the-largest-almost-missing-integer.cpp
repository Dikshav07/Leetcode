class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        unordered_map<int,int>mp;
        int n=nums.size();
        if(n==k)return *max_element(nums.begin(),nums.end());
        for(int i=0;i<=n-k;++i)
        {
            for(int j=0;j<k;++j)
            {
                mp[nums[i+j]]++;
            }
        }
        int ans=-1;
        for(auto& it:mp)
        {
            if(it.second==1)ans=max(ans,it.first);
        }
        return ans;
    }
};