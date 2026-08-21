class Solution {
public:
    long long findKthSmallest(vector<int>& coins, int k) {
        long long l=1,r=1e18,ans=1;
        while(l<=r)
        {
            long long mid=l+(r-l)/2;
            if(calculate(mid,coins)>=k)
            {
                ans=mid;
                r=mid-1;
            }
            else l=mid+1;
        }
        return ans-1;
    }
    long long calculate(long long x,vector<int>& coins)
    {
        long long ans=0;
        int n=coins.size(),total=1<<n;
        for(int i=1;i<total;++i)
        {
            long long lcm=LCM(i,coins);
            int bits=__builtin_popcount(i);
            if(bits&1)ans+=(x-1)/lcm;
            else ans-=(x-1)/lcm;
        }
        return ans;
    }
    long long LCM(int mask,vector<int>& coins)
    {
        long long lcm=1;
        int n=coins.size();
        for(int i=0;i<n;++i)
        {
            if(mask&(1<<i))
            {
                lcm=(lcm*coins[i])/gcd(lcm,(long long)coins[i]);
                if(lcm>1e18)return 1e18;
            }
        }
        return lcm;
    }
};