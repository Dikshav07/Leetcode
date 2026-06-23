class Solution {
public:
    static constexpr int MOD = 1000000007;

    int zigZagArrays(int n, int l, int r) {
        int m = r + 2;
        vector<vector<long long>> vec(m, vector<long long>(2, 0));
        for (int val=l; val <= r; ++val) {
            vec[val][0] = 1;
            vec[val][1] = 1;
        }

        vector<long long> lp(m, 0);
        vector<long long> gp(m, 0);

        for (int val = l; val <= r; ++val) {
            lp[val + 1] =
                (lp[val] + vec[val][0]) % MOD;

            gp[val + 1] =
                (gp[val] + vec[val][1]) % MOD;
        }

        for (int len=2; len<=n; ++len) {
            vector<long long> nexl(m, 0);
            vector<long long> nexg(m, 0);

            long long sum = gp[r + 1];

            for (int i=l; i<=r; ++i) {
                vec[i][0] = lp[i] % MOD;

                vec[i][1] =(sum- gp[i+1] + MOD) % MOD;

                nexl[i+1] =(nexl[i] + vec[i][1]) % MOD;

                nexg[i+1] =
                    (nexg[i] +vec[i][0]) % MOD;
            }


            lp.swap(nexl);
            gp.swap(nexg);
        }

        long long ans = 0;
        for (int i=l; i<=r; ++i) {
            ans=(ans + vec[i][0] + vec[i][1]) % MOD;
        }



        return ans;
    }
};