class Solution {
public:
    long long sumAndMultiply(int n) {
        long long sum=0;
        long long newn=0;
        long long p=1;
        while(n>0){
            int digit=n%10;
            sum+=digit;
            if(digit!=0){
                newn+=digit*p;
                p *= 10;
            }
            n/=10;
        }
        return sum*newn;;
    }
};