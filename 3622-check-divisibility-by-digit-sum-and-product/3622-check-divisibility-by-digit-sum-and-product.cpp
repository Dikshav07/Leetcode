class Solution {
public:
    bool checkDivisibility(int n) {
        int tot=0,mul=1,tmp=n;
        while(n)
        {
            int x=n%10;
            tot+=x,mul*=x;
            n/=10;
        }
        return (tmp%(tot+mul))==0;
    }
};