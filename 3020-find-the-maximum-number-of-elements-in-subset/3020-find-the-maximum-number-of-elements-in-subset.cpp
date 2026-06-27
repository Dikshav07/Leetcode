class Solution {
public:
    int maximumLength(vector<int>& nums) {
          unordered_map<long long, int> mp;
        for (int x : nums)
            mp[x]++;
        int ans = 1;
        if (mp.count(1)) {
            int ones = mp[1];
            ans = max(ans, ones % 2 ? ones : ones - 1);
        }
        for (auto& [num, freq] : mp) {
            if (num == 1)
                continue;

            long long cur = num;
            int len = 0;

            while (mp.count(cur) && mp[cur] >= 2) {
                len += 2;
                cur = cur * cur;

                if (cur > 1e18)
                    break;
            }

            if (mp.count(cur)) {
                len += 1; 
            } else {
                len -= 1;
            }
            ans = max(ans, len);
        }

        return ans;
    }
};