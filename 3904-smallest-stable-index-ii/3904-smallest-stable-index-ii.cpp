class Solution {
public:
    int firstStableIndex(vector<int>& nums, int k) {
         int ans = -1;
        int n = nums.size();
        vector<int>minimum(n,0) , maximum(n,0);
        int maxi = INT_MIN , mini = INT_MAX;
        for(int i = 0 ;i<n;i++){
            maxi=max(nums[i],maxi);
            mini=min(mini,nums[n-i-1]);
            maximum[i]=maxi;
            minimum[n-i-1]=mini;
        }
        for(int i = 0 ;i<n;i++){
            if(maximum[i]-minimum[i]<=k){
                ans =i;
                return ans;
            }
        }
        return ans;
    }
};