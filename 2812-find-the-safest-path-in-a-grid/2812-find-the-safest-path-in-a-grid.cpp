class Solution {
public:
    bool possible(vector<vector<int>>& fact, int& maxi){
        int n = fact.size();
        vector<vector<int>> vis(n,vector<int>(n,false));
        if(fact[0][0]<maxi || fact[n-1][n-1]<maxi) return false;
        queue<pair<int,int>> q;
        q.push({0,0});
        vis[0][0] = true;
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};
        while(!q.empty()){
            int r = q.front().first;
            int c = q.front().second;
            q.pop();
            if(r==n-1 && c==n-1) return true;
            for(int i = 0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                if(nr>=0 && nc>=0 && nr<n && nc<n && fact[nr][nc]>=maxi && !vis[nr][nc]){
                    q.push({nr,nc});
                    vis[nr][nc] = true;
                }
            }
        }
        return false;
    }
    int maximumSafenessFactor(vector<vector<int>>& grid) {
        const int n = grid.size();
        vector<vector<int>> fact(n,vector<int>(n,-1));
        queue<pair<int,int>> q;
        for(int i = 0; i<n; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j]==1){
                    q.push({i,j}); 
                    fact[i][j] = 0; 
                } 
            }
        }
        vector<int> dr = {-1,0,1,0};
        vector<int> dc = {0,1,0,-1};
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i<size; i++){
                int r = q.front().first;
                int c = q.front().second;
                q.pop();
                for(int j = 0; j<4; j++){
                    int nr = r + dr[j];
                    int nc = c + dc[j];
                    if(nr>=0 && nc>=0 && nr<n && nc<n && fact[nr][nc]==-1){
                        fact[nr][nc] = fact[r][c] + 1;
                        q.push({nr,nc});
                    }
                }
            }
        }
        int low = 0;
        int high = 2*n;
        int ans = -1;
        while(low <= high){
            int mid = low + (high-low)/2;
            if(possible(fact,mid)){
                low = mid+1;
                ans = mid;
            }
            else high = mid - 1;
        }
        return ans;
    }
};