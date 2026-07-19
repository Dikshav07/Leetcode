class Solution {
public:
    vector<vector<string>> findDuplicate(vector<string>& paths) {        
        unordered_map<string, vector<string>>mp;
        vector<vector<string>> dup_group;
        
        for(const auto &x : paths) {
            string path = "", filePath, fileName, content;
            
            for(int i = 0; i < x.size(); i++) {
                if(x[i] == ' ') {
                    i++;
                    fileName = "";
                    
                    while(x[i] != '(') {
                        fileName += x[i];
                        i++;
                    }
                    
                    i++;
                    content = "";
                    
                    while(x[i] != ')') {                        
                        content += x[i];
                        i++;
                    }
                    
                    filePath = path + '/' + fileName;
                    mp[content].push_back(filePath);
                }            
                else path += x[i];
            }            
        }
        
        for(const auto &x : mp) {
            if(x.second.size() > 1) {
                dup_group.push_back(x.second);
            }
        }
        
        return dup_group;
        
    }
};