class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> mp;

        for (string &s : paths) {
            stringstream ss(s);
            string dir;
            ss >> dir;
            string file;
            while (ss >> file) {
                int l = file.find('(');
                int r = file.find(')');
                string name = file.substr(0, l);
                string content = file.substr(l + 1, r - l - 1);

                mp[content].push_back(dir + "/" + name);
            }
        }

        vector<vector<string>> ans;

        for (auto &x : mp)
            if (x.second.size() > 1)
                ans.push_back(x.second);

        return ans;
    }
};