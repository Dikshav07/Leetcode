class Solution {
public:
    int getSum(string s, int start, int end) {
        int sum = 0;

        while (start < end) {
            sum += s[start] - '0';
            start++;
        }

        return sum;
    }

    string digitSum(string s, int k) {
        while (s.length() > k) {
            string ans = "";

            for (int i = 0; i < s.length(); i += k) {
                int end = min(i + k, (int)s.length());
                ans += to_string(getSum(s, i, end));
            }

            s = ans;
        }

        return s;
    }
};