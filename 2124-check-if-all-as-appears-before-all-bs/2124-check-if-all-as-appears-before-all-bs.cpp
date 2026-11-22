class Solution {
public:
    bool checkString(string s) {
        int ok=0;
        for(auto& it:s)
        {
            if(it=='b')ok=1;
            else if(ok)return 0;
        }
        return 1;
    }
};
