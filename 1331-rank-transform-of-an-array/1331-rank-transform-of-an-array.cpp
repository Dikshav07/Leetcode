class Solution {
public:
    vector<int> arrayRankTransform(vector<int>& arr) {
        vector<int> sa = arr;
        sort(sa.begin(), sa.end());
        unordered_map<int, int> rank;

        int r = 1;
        for (int n : sa) {
            if (rank.find(n) == rank.end()) {
                rank[n] = r++;
            }
        }
        for(int i = 0; i < arr.size(); i++){
            arr[i] = rank[arr[i]];
        }
        return arr;
    }
};