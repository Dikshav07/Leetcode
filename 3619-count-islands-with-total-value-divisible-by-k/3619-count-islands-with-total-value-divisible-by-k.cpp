class Solution{
public:
    void dfs(int i,int j,vector<vector<int>>& grid,vector<vector<int>>& vis,long long& sum)
    {
        int n=grid.size(),m=grid[0].size();
        vis[i][j]=1,sum+=grid[i][j];
        int dx[4]={-1,0,1,0};
        int dy[4]={0,1,0,-1};
        for(int k=0;k<4;++k)
        {
            int ni=i+dx[k],nj=j+dy[k];
            if(ni>=0 && ni<n && nj>=0 && nj<m && grid[ni][nj]!=0 && !vis[ni][nj])
            {
                dfs(ni,nj,grid,vis,sum);
            }
        }
    }
    int countIslands(vector<vector<int>>& grid, int k) {
        int n=grid.size(),m=grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int ans=0;
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<m;++j)
            {
                if(grid[i][j]!=0 && !vis[i][j])
                {
                    long long sum=0;
                    dfs(i,j,grid,vis,sum);
                    if(sum%k==0)ans++;
                }
            }
        }
        return ans;
    }
};