class Solution {
public:
    string maxSumOfSquares(int num, int sum) {
        if(num*9<sum)return "";
        string ans;
        for(int i=1;i<=num;++i)
        {
            int dig=min(9,sum);
            ans+=char('0'+dig);
            sum-=dig;
        }
        if(sum!=0)return "";
        return ans;
    }
};