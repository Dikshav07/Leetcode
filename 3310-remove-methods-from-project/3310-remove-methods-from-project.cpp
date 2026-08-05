class Solution {
public:
    vector<int> remainingMethods(int n, int k, vector<vector<int>>& nums) {
        int m = nums.size();
        set<int> st;
        vector<int> adj[n];
        for(auto it : nums)
        {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
        }

        queue<int> q;
        q.push(k);
        st.insert(k);
        vector<int> visited(n,0);
        visited[k] = 1;
        while(!q.empty())
        {
            int node = q.front();
            q.pop();

            for(auto it : adj[node])
            {
                if(visited[it] == 0){
                st.insert(it);
                q.push(it);
                visited[it] = 1;
                }
            }
        }
        
        bool flag = false;

        for(int i = 0 ; i < m ; i++)
        {
            int x = nums[i][1];
            int y = nums[i][0];
            if(st.find(y) == st.end())
            if(st.find(x) != st.end())
            flag = true;
        }

        vector<int> ans;
        if(flag == true)
        {
            for(int i = 0 ; i < n ; i++)
            ans.push_back(i);
        }
        else
        {
            for(int i = 0 ; i < n ; i++)
            {
                if(st.find(i) == st.end())
                ans.push_back(i);
            }
        }

        return ans;



    }
};