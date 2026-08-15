class Solution {
public:
    int longestSubsequence(vector<int>& nums) {
        int total = 0;
        bool anyNonZero = false;
        for (int x : nums) {
            total ^= x;
            if (x != 0) anyNonZero = true;
        }
        int n = nums.size();
        if (total != 0) return n;
        if (anyNonZero) return n - 1;
        return 0;
    }
};