class Solution {
public:
    string smallestPalindrome(string s) {
        vector<int> map(26,0);

        int n = s.size();
        for(int i = 0 ; i <= n/2 - 1; i++){
            map[s[i] - 'a']++;
        }
        char single;
        if(n % 2 != 0)  single = s[n/2];
        string ans = "";
        vector<int> map2 = map;
        for(int i = 0 ; i < 26 ; i++){
            while(map[i]){
                ans += 'a' + i;
                map[i]--;
            }
        }
        if(n % 2 != 0) ans += single;
        for(int i = 25 ; i >= 0 ; i--){
            while(map2[i]){
                ans += 'a' + i;
                map2[i]--;
            }
        }
        return ans;

    }
};