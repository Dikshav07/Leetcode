class Solution {
public:
    bool sumGame(string num) {
        int a=0,cnt=0;
        for(int i=0;i<num.size();++i)
        {
            if(i<num.size()/2)
            {
                if(num[i]=='?')cnt++;
                else a+=num[i]-'0';
            }
            else
            {
                if(num[i]=='?')cnt--;
                else a-=num[i]-'0';
            }
        }
        return cnt*9+a*2!=0;
    }
};