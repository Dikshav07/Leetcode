class Solution {
public:
    int maximumSaleItems(vector<vector<int>>& items, int budget) {
        int n = items.size();
        unordered_map<int,int> mpp;
        sort(items.begin(),items.end(),[](vector<int>&a,vector<int>&b){
            return a[0] < b[0];
        });
        // A factor cant contribute to itself to we -1 when we iterate through the items vector
        for(int i = 0;i<n;i++){
            int x = items[i][0];
            for(int j = 1;j*j<=x;j++){
                if(x%j == 0){
                    mpp[j]++;
                    if(x != j*j){
                        mpp[x/j]++;
                    }
                }
            }
        }

       priority_queue<pair<double,int>,vector<pair<double,int>>,greater<pair<double,int>>> st;
        for(int i =0;i<n;i++){
            int cnt = mpp[items[i][0]] -1;//a factor cant contribute to itsel
            double cost = items[i][1]*1.0;
            if(cnt > 0) cost = cost/(2*1.0);
            // cout<<cost<<" "<<cnt<<endl;
            st.push({cost,-1*cnt});
        }
        int ans = 0;
        while(!st.empty() && budget != 0){
            double cost = st.top().first;
            int cnt = -1*st.top().second;
            // cout<<cost<<" "<<cnt<<endl;
            st.pop();
            if(cost > budget*1.0) break;
            if(cnt > 0 && 2*cost > budget*1.0){
                continue;
            }
            if(cnt == 0){
                //no multiplier
                int tc = budget/cost;
                budget -= (int)(cost*tc);
                ans += tc;
                break;
            }
            int tc = budget/(2*cost);
            tc = min(tc,cnt);
            ans += tc*2;
            cnt -= tc;
            budget -= 2*cost*tc;
            if(cnt == 0){
                st.push({cost*2,0});
            }
            else{
                st.push({cost,-cnt});
            }
        }
        return ans;
    }
};