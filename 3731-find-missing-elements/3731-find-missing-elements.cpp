class Solution {
public:
    vector<int> findMissingElements(vector<int>& nums) {
         sort(nums.begin(),nums.end());
        int maxi=nums[nums.size()-1];
        int mini=nums[0];
        vector<int>ans;
        for(int i=1;i<nums.size();i++)
        {
            while(nums[i]!=mini+1)
            {
                ans.push_back(mini+1);
                mini++;
            }
            mini=nums[i];
        }
        return ans;
    }
};