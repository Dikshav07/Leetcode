class Solution {
public:
    bool isAlienSorted(vector<string>& words, string order) {
        unordered_map<char, char> mo;
        for (int i = 0; i < order.size(); ++i) {
            mo[order[i]] = i + 'a';
        }    
        for (auto& s: words) {
            for (auto& ch: s) {
                ch = mo[ch];
            }
        }
        auto cp = words;
        sort(cp.begin(), cp.end());
        return cp == words;
    }
};