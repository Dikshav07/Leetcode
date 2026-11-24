class Solution {
public:
    int maxLength(vector<int>& nums) {
        auto Fact=[&](int x)
        {
            vector<int>res(4,0);
            int primes[4]={2,3,5,7};
            for(int i=0;i<4;++i)
            {
                while(x%primes[i]==0)
                {
                    x/=primes[i];
                    res[i]++;
                }
            }
            return res;
        };
        int n=nums.size(),ans=1;
        for(int i=0;i<n;++i)
        {
            vector<int>mn(4,INT_MAX),mx(4,0),tot(4,0);
            for(int j=i;j<n;++j)
            {
                vector<int>F=Fact(nums[j]);
                for(int p=0;p<4;++p)
                {
                    mn[p]=min(mn[p],F[p]);
                    mx[p]=max(mx[p],F[p]);
                    tot[p]+=F[p];
                }
                int ok=1;
                for(int p=0;p<4;++p)
                {
                    if(tot[p]!=mn[p]+mx[p])
                    {
                        ok=0;
                        break;
                    }
                }
                if(ok)ans=max(ans,j-i+1);
            }
        }
        return ans;
    }
};
