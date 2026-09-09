class Solution {
public:
    long long countCommas(long long n) {
     long long req=999;
        long long ans=0;
        while(n>req){
            ans+=n-req;
            req=req*1000+999;
        }
        return ans;   
    }
};