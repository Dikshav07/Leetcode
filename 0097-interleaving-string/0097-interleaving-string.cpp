class Solution {
public:
   
    bool helper(string &s1, string &s2, string &s3, int i, int j, int k, vector<vector<int>>&dp){
        if(i == s1.size()){
            while(j < s2.size() && k < s3.size() && s2[j] == s3[k]){
                j ++;
                k ++;
            }
            return j == s2.size() && k == s3.size();
        }

        if(j == s2.size()){
            while(i < s1.size() && k < s3.size() && s1[i] == s3[k]){
                i ++;
                k ++;
            }
            return i == s1.size() && k == s3.size();
        }

        if(dp[i][j] != -1) return dp[i][j];
          
        bool way1 = false, way2 = false;

        if(s1[i] == s3[k]){
            way1 = helper(s1, s2, s3, i + 1, j, k + 1, dp);
        }  
        if(s2[j] == s3[k]){
            way2 = helper(s1, s2, s3, i, j + 1, k + 1, dp);
        }

        return dp[i][j] = way1 || way2;

    }


    bool isInterleave(string s1, string s2, string s3) {
        
        vector<vector<int>>dp(s1.size(), vector<int>(s2.size(), -1));
        return helper(s1, s2, s3, 0, 0, 0, dp);
    }
};