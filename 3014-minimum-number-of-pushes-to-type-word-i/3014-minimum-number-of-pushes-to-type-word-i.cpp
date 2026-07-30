class Solution {
public:
    typedef int ll;

    int minimumPushes(string word) {
        ll sum = 0;
        ll count = 0;
        ll num = 1;

        for (ll i = 0; i < word.size(); i++) {
            count++;

            if (count > 8) {
                count = 1;
                num++;
            }

            sum += num;
        }

        return sum;
    }
};