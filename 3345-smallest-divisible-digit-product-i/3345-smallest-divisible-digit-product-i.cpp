class Solution {
public:
    int smallestNumber(int n, int t) {
        int product=1;
        int rem=n;
        while(rem>0){
            product*=rem%10;
            rem/=10;
        }
        if(product%t==0){
            return n;
        }
        else{
            return smallestNumber(n+1,t);
        }
    }
};