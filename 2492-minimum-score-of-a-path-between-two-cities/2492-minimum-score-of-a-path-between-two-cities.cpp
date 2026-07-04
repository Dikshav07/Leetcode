class Solution {
public:
    vector<vector<pair<int,int>>> BuildAdjList(int n, vector<vector<int>>& roads){
        vector<vector<pair<int,int>>> adj(n+1);
        for(int i=0;i<roads.size();i++){
            int u=roads[i][0];
            int v=roads[i][1];
            int w=roads[i][2];
            adj[u].push_back({v,w});
            adj[v].push_back({u,w});
        }
        return adj;
    }
    int BFS(int n,vector<vector<pair<int,int>>> &adj){
        int ans=INT_MAX;
        vector<bool> vis(n+1,false);
        queue<int>q;
        q.push(1);
        vis[1]=true;
        while(!q.empty()){
            int node=q.front();
            q.pop();
            for(auto neighbour:adj[node]){
                int v=neighbour.first;
                int w=neighbour.second;
                ans=min(ans,w);
                if(!vis[v]){
                    vis[v]=true;
                    q.push(v);
                }
            }
        }
        return ans;
    }
    int minScore(int n, vector<vector<int>>& roads) {
        vector<vector<pair<int,int>>> adj=BuildAdjList(n,roads);
        int res=BFS(n,adj);
        return res;
    }
};