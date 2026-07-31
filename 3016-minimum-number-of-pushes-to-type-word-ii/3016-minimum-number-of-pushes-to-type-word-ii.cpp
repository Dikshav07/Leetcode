class Solution {
public:
    int minimumPushes(string word) {
        vector<int> freq(26);
        for(char c:word)
            freq[c-'a']++;
        int cnt=0;
        sort(freq.begin(),freq.end(),greater<int>());
        for(int i=0;i<freq.size();i++)
        {
            if(freq[i]==0)
                break;
            cnt+=freq[i]*(i/8+1);
        }
        return cnt;
    }
};