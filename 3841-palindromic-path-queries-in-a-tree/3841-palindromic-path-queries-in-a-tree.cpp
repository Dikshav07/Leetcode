class Solution {
public:
    vector<bool> palindromePath(int n, vector<vector<int>>& edges, string s, vector<string>& queries) {
     vector<vector<int>>adj(n);
        for(auto& it:edges)
        {
            adj[it[0]].push_back(it[1]);
            adj[it[1]].push_back(it[0]);
        }
        int lg=1;
        while((1<<lg)<=n)lg++;
        vector<vector<int>>up(lg,vector<int>(n,0));
        vector<int>depth(n,0),In(n),Out(n),sz(n,1);
        vector<int>mask(n,0),order;
        order.reserve(n);
        vector<pair<int,int>>st={{0,0}};
        while(!st.empty())
        {
            auto [u,p]=st.back();
            st.pop_back();
            In[u]=order.size();
            order.push_back(u);
            up[0][u]=p;
            mask[u]=(u==0?0:mask[p])^(1<<(s[u]-'a'));
            for(auto& it:adj[u])
            {
                if(it==p)continue;
                depth[it]=depth[u]+1;
                st.push_back({it,u});
            }
        }
        for(int i=n-1;i>0;--i)
        {
            int u=order[i];
            sz[up[0][u]]+=sz[u];
        }
        for(int i=0;i<n;++i)Out[i]=In[i]+sz[i]-1;
        for(int i=1;i<lg;++i)
        {
            for(int j=0;j<n;++j)
            {
                up[i][j]=up[i-1][up[i-1][j]];
            }
        }
        auto lca=[&](int u,int v)
        {
            if(depth[u]<depth[v])swap(u,v);
            int diff=depth[u]-depth[v];
            for(int i=0;i<lg;++i)
            {
                if(diff&(1<<i))u=up[i][u];
            }
            if(u==v)return u;
            for(int i=lg-1;~i;--i)
            {
                if(up[i][u]!=up[i][v])
                {
                    u=up[i][u],v=up[i][v];
                }
            }
            return up[0][u];
        };
        vector<int>bit(n+1,0);
        auto add=[&](int idx,int val)
        {
            for(int i=idx+1;i<=n;i+=i&-i)bit[i]^=val;
        };
        auto update=[&](int l,int r,int val)
        {
            add(l,val);
            if(r+1<n)add(r+1,val);
        };
        auto get=[&](int idx)
        {
            int res=0;
            for(int i=idx+1;i>0;i-=i&-i)res^=bit[i];
            return res;
        };
        vector<bool>ans;
        for(auto&it:queries)
        {
            string op;
            int u,v;
            char c;
            stringstream ss(it);
            ss>>op>>u;
            if(op=="update")
            {
                ss>>c;
                int delta=(1<<(s[u]-'a'))^(1<<(c-'a'));
                update(In[u],Out[u],delta);
                s[u]=c;
            }
            else
            {
                ss>>v;
                int w=lca(u,v);
                int mu=mask[u]^get(In[u]);
                int mv=mask[v]^get(In[v]);
                int msk=mu^mv^(1<<(s[w]-'a'));
                ans.push_back((msk&(msk-1))==0);
            }
        }
        return ans;
    }
};