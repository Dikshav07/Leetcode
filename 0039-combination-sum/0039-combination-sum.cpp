class Solution {
public:
    vector<vector<int>> ans;
    vector<vector<int>> combinationSum(vector<int>& candidates, int target) {
        ranges::sort(candidates);
        vector<int> curr;
        backtrack(candidates, curr, target, 0, 0);
        return ans;
    }

    void backtrack(vector<int>& candidates, vector<int>& curr, int target, int sum, int idx) {
        if (sum == target) {
            ans.push_back(curr);
            return;
        }
        
        int n = candidates.size();
        for (int i = idx; i < n; i++) {
            if (sum + candidates[i] > target)
                return;
            
            curr.push_back(candidates[i]);
            backtrack(candidates, curr, target, sum + candidates[i], i);
            curr.pop_back();
        }
    }
};