class Solution {
public:
    vector<int> assignTasks(vector<int>& servers, vector<int>& tasks) {
        int n = servers.size();
        int m = tasks.size();

        priority_queue<vector<int>, vector<vector<int>>, greater<>> freeServers;
        priority_queue<vector<long long>, vector<vector<long long>>, greater<>> busyServers;

        for(int i = 0; i < n; i++)
        {
            freeServers.push({servers[i], i});
        }

        vector<int> res;
        for(int i = 0; i < m; i++)
        {
            while(!busyServers.empty() && busyServers.top()[0] <= i)
            {
                auto curr = busyServers.top();
                int wt = curr[1], idx = curr[2];

                freeServers.push({wt, idx});
                busyServers.pop();
            }

            if(!freeServers.empty())
            {
                auto curr = freeServers.top();
                int wt = curr[0], idx = curr[1];
                res.push_back(idx);
                busyServers.push({i + tasks[i], wt, idx});
                freeServers.pop();
            }
            else
            {
                auto curr = busyServers.top();
                long long t = curr[0];
                int wt = curr[1], idx = curr[2];
                res.push_back(idx);
                busyServers.pop();
                busyServers.push({t + tasks[i], wt, idx});
            }
        }

        return res;
    }
};