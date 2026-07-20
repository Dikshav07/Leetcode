class Solution {
public:
    vector<vector<int>> shiftGrid(vector<vector<int>>& arr, int k) {
        int r = arr.size(), c = arr[0].size();
        vector<int> vec;
        for(auto a:arr) for(auto b:a) vec.push_back(b);
        int cur = 0;
        k %= vec.size();
        rotate(begin(vec), vec.end() - k, vec.end());
        vector<vector<int>> ans(r, vector<int>(c));
        for(int i = 0; i < r; ++ i){
            for(int j = 0; j < c; ++ j){
                ans[i][j] = vec[cur ++];
            }
        }
        return ans;
    }
};