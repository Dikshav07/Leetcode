class Solution {
public:
    int romanToInt(string s) {
        unordered_map<char, int> rv;
        // roman value
        rv['I'] = 1;
        rv['V'] = 5;
        rv['X'] = 10;
        rv['L'] = 50;
        rv['C'] = 100;
        rv['D'] = 500;
        rv['M'] = 1000;

        int res = 0;
        int prev = 0;
        int curr;

        for (auto& rom : s) {
            curr = rv[rom];
            res += (curr>prev) ? curr - 2 * prev : curr;
            prev = curr;
        }

        return res;
    }
};