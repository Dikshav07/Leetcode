class Solution {
public:
    int n;
    vector<vector<vector<int>>> dp;
    int solveForAlice(vector<int>& piles,int person,int idx,int M)
    {
        if(idx>=n)
        return 0;

        M=min(M,n);

        if(dp[person][idx][M] != -1)
        return dp[person][idx][M];

        int stones=0;
        int result=(person==1) ? -1 : INT_MAX;

        for(int x=1;x<=min(2*M,n-idx);x++)
        {
            stones+=piles[idx+x-1];
            if(person==1)       //Alice
            {
                result=max(result,stones+solveForAlice(piles,0,idx+x,max(M,x)));
            }
            else              
            {
                result=min(result,solveForAlice(piles,1,idx+x,max(M,x)));
            }
        }
        return dp[person][idx][M]=result;
    }
    int stoneGameII(vector<int>& piles) {
        n=piles.size();
        dp.resize(2,vector<vector<int>>(n+1,vector<int>(n+1,-1)));
        return solveForAlice(piles,1,0,1);
    }
};