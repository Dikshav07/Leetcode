class Solution {
public:
    using ll = long long;
    struct Fenwick {
        int n;
        vector<int> bit;
        Fenwick(int n) : n(n), bit(n + 1, 0) {}
        void add(int idx, int val) {
            while (idx <= n) {
                bit[idx] += val;
                idx += idx & -idx;
            }
        }
        int query(int idx) {
            int res = 0;
            while (idx > 0) {
                res += bit[idx];
                idx -= idx & -idx;
            }
            return res;
        }
    };

    long long countMajoritySubarrays(vector<int>& nums, int target) {
        int n = nums.size();
        Fenwick ft(2 * n + 5);
        int offset = n + 2;
        int pref = 0;
        long long ans = 0;
        ft.add(offset, 1);  
        for (int x : nums) {
            pref += (x == target ? 1 : -1);
            int idx = pref + offset;
            ans += ft.query(idx - 1);
            ft.add(idx, 1);
        }

        return ans;
    }
};