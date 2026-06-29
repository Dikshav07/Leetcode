class Solution {
public:
    int numOfStrings(vector<string>& patterns, string word) {
         int cnt = 0;

        for (const string& str : patterns)
            cnt += word.contains(str);

        return cnt;
    }
};