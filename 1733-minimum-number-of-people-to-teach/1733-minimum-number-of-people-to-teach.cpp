class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int m = languages.size();
        vector<unordered_set<int>> who(m);
        for(int i = 0; i < m; i++) {
            who[i] = unordered_set<int>(languages[i].begin(), languages[i].end());
        }

        vector<pair<int,int>> need; 
        for(auto &f : friendships) {
            int u = f[0]-1, v = f[1]-1;
            bool canTalk = false;
            for(int lang : who[u]) {
                if(who[v].count(lang)) {
                    canTalk = true;
                    break;
                }
            }
            if(!canTalk) need.push_back({u, v});
        }

        int ans = INT_MAX;
        for(int lang = 1; lang <= n; lang++) {
            unordered_set<int> taught;
            for(auto &[u, v] : need) {
                if(!who[u].count(lang)) taught.insert(u);
                if(!who[v].count(lang)) taught.insert(v);
            }
            ans = min(ans, (int)taught.size());
        }

        return ans;
    }
};