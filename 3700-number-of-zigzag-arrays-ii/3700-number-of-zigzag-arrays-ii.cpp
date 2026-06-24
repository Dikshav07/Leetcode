class Solution {
public:
    static const long long MOD = 1000000007LL;
    using Matrix = vector<vector<long long>>;
    Matrix multiply(const Matrix& A, const Matrix& B) {
        int n = A.size();
        Matrix C(n, vector<long long>(n, 0));
        for (int i = 0; i < n; i++) {
            for (int k = 0; k < n; k++) {
                if (!A[i][k]) continue;
                long long aik = A[i][k];
                for (int j = 0; j < n; j++) {
                    if (!B[k][j]) continue;
                    C[i][j] = (C[i][j] + aik * B[k][j]) % MOD;
                }
            }
        }
        return C;
    }

    Matrix power(Matrix base, long long exp) {
        int n = base.size();

        Matrix res(n, vector<long long>(n, 0));
        for (int i=0; i<n; i++) res[i][i] = 1;

        while (exp)
        {
            if (exp & 1)
                res = multiply(res, base);

            base = multiply(base, base);
            exp>>=1;
        }

        return res;
    }

    vector<long long> apply(const Matrix& M, const vector<long long>& v) {
        int n = M.size();
        vector<long long> res(n, 0);

        for (int i = 0; i < n; i++) {
            long long cur = 0;
            for (int j=0; j<n; j++) {
                cur = (cur+M[i][j] * v[j]) % MOD;
            }
            res[i] = cur;
        }
        return res;
    }

    int zigZagArrays(int n, int l, int r) {
        int m = r - l + 1;

        if (n == 1)
            return m;

        if (m == 1)
            return 0;

        int S = 2 * m;

        Matrix T(S, vector<long long>(S, 0));

        for (int y = 1; y <= m; y++) {
            int row = y - 1;

            for (int x = 1; x < y; x++) {
                T[row][m + x - 1] = 1;
            }
        }
        for (int y = 1; y <= m; y++) {
            int row = m + y - 1;

            for (int x = y + 1; x <= m; x++) {
                T[row][x - 1] = 1;
            }
        }

        vector<long long> base(S, 0);
        for (int y = 1; y <= m; y++) {
            base[y - 1] = y - 1;      
            base[m + y - 1] = m - y;  
        }

        if (n == 2) {
            long long ans = 0;
            for (long long x : base)
                ans = (ans + x) % MOD;
            return (int)ans;
        }

        Matrix P = power(T, n - 2);
        vector<long long> finalState = apply(P, base);
        long long ans = 0;
        for (long long x : finalState) {
            ans = (ans + x) % MOD;
        }

        return (int)ans;
    }
};