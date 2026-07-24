class Solution {
private:
    void solve(vector<bool>& vec2, const vector<bool>& vec, int curr, int m) {
        for (int x = 0; x < m; x++) {
            if (vec[x]) {
                vec2[x ^ curr] = true;
            }
        }
    }

    void solve2(vector<bool>& vec, const vector<int>& nums, int k) {
        for (int i = 0; i <= k; i++) {
            int p = nums[i] ^ nums[k];
            vec[p] = true;
        }
    }

    int check(const vector<bool>& vec2, int m) {
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if (vec2[i]) cnt++;
        }
        return cnt;
    }
public:
    int uniqueXorTriplets(vector<int>& nums) {
        vector<int> res = nums;
        const int m = 2048;
        vector<bool> vec(m, false);
        vector<bool> vec2(m, false);
        int n = nums.size();

        for (int k = 0; k < n; k++) {
            solve(vec2, vec, nums[k], m);
            solve2(vec, nums, k);
            vec2[nums[k]] = true;
        }

        return check(vec2, m);
    }
};
