class Solution {
public:
    vector<vector<int>> subsetsWithDup(vector<int>& nums) {
        vector<vector<int>> res= {};
        vector<int> subset;
        int n = nums.size();
        sort(nums.begin(), nums.end());
        function<void(int)> backtrack = [&](int index)
        {
            if(index == n)
            {
                res.push_back(subset);
                return;
            }
            subset.push_back(nums[index]);
            backtrack(index+1);
            subset.pop_back();
            while(index+1 < n && nums[index] == nums[index+1]) index++;
            backtrack(index+1);
        };  
        backtrack(0);

        return res;
    }
};