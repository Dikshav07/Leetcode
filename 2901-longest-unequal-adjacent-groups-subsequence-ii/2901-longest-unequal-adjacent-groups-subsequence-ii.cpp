class Solution {
public:
    bool checkHammingDistance(string word1, string word2) {
        if(word1.length() != word2.length())
        return false;

        int m = word1.length();
        int dist = 0;
        for(int i = 0; i < m; i++)
        {
            if(word1[i]!=word2[i])
            {
                dist++;

                if(dist> 1)
                return false;
            }
        }

        return true;
    }

    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        
        vector<int> dp(n, 1);
        vector<int> parent(n, -1);
        int longestSub = 1;
        int longestSubIdx = 0;

        for(int i = 0; i < n; i++)
        {
            for(int j = 0; j < i; j++)
            {
                if(groups[j] != groups[i] && checkHammingDistance(words[i], words[j]))
                {
                    if(dp[i] < dp[j] + 1)
                    {
                        dp[i] = dp[j] + 1;
                        parent[i] = j;

                        if(longestSub < dp[i])
                        {
                            longestSub = dp[i];
                            longestSubIdx = i;
                        }
                    }
                }
            }
        }

        vector<string> res;

        while(longestSubIdx != -1)
        {
            res.push_back(words[longestSubIdx]);
            longestSubIdx = parent[longestSubIdx];
        }

        reverse(res.begin(), res.end());

        return res;
    }
};