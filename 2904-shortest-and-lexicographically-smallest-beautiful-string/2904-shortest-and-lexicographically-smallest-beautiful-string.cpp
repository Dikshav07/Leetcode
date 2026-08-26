class Solution {
public:
    string shortestBeautifulSubstring(string s, int k) {
        int temp=k;
        int n=s.size();
        string ans="";
        while(temp<=n)
        {
            int left=0,ones=0;
            for(int right=0;right<n;++right)
            {
                if(s[right]=='1')
                {
                    ones++;
                }
                while(right-left+1>temp)
                {
                    if(s[left]=='1')
                    {
                        ones--;
                    }
                    left++;
                }
                if(ones==k && (ans.empty() || s.substr(left,temp)<ans))
                {
                    ans=s.substr(left,temp);
                }
            }
            if(!ans.empty())
            {
                break;
            }
            temp++;
        }
        return ans;
    }
};