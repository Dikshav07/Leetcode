typedef long long ll;

class Solution {
public:
    bool isValid(vector<vector<pair<int, int>>>& adj, 
    vector<bool>& online, ll k, ll mid) {
        int n = adj.size();
        priority_queue<pair<ll, int>, vector<pair<ll, int>>, greater<>> pq;
        vector<ll> dist(n, LLONG_MAX);
        pq.push({0, 0});
        dist[0] = 0;
        while(!pq.empty()) {
            auto [cost, node] = pq.top(); pq.pop();
            if(cost != dist[node]) continue;
            for(auto &[nei, w] : adj[node]) {
                if(!online[nei]) continue;
                if(w < mid) continue;
                ll newCost = cost + w;
                if(newCost <= k && newCost < dist[nei]) {
                    dist[nei] = newCost;
                    pq.push({newCost, nei});
                }
            }
        }
        return dist[n-1] <= k;
    }
    int findMaxPathScore(vector<vector<int>>& edges, vector<bool>& online, long long k) {
        int n = online.size();
        vector<vector<pair<int, int>>> adj(n);
        int low = 0, high = 0;
        for(auto &e : edges) {
            int u = e[0], v = e[1], w = e[2];
            adj[u].push_back({v, w});
            high = max(high, w);
        }
        int ans = -1;
        while(low <= high) {
            int mid = (low + high) / 2;
            if(isValid(adj, online, k, mid)) {
                ans = mid;
                low = mid + 1;
            }
            else high = mid - 1;
        }
        return ans;
    }
};