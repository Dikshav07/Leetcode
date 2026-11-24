class Solution {
public:
    typedef pair<int,int> P;
    vector<int> getOrder(vector<vector<int>>& tasks) {
        int n = tasks.size();
        for(int i = 0; i < n; i++)
        {
            tasks[i].push_back(i);
        }

        sort(tasks.begin(), tasks.end());

        priority_queue<P, vector<P>, greater<P>> pq;
        vector<int> res;

        int i = 0;
        long long time = 0;

        while(!pq.empty() || i < n)
        {
            if(pq.empty() && time < tasks[i][0])
            time = tasks[i][0];

            
            while(i < n && tasks[i][0] <= time)
            {
                pq.push({tasks[i][1], tasks[i][2]});
                i++;
            }

            auto [processingTime, idx] = pq.top();
            pq.pop();

            res.push_back(idx);
            time += processingTime;
        }

        return res;
    }
};