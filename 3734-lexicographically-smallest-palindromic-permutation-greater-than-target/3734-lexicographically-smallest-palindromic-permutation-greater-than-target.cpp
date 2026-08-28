class Solution {
public:
    void recur(vector<int>& nums,string target,int idx,string cur,int len,string& ans,char oddch,int oddcnt,set<pair<int,string>>& st,string mx)
    {
        if(ans!=mx)return;
        pair<int,string>p={idx,cur};
        if(st.find(p)!=st.end())return;
        if(idx==len)
        {
            string temp=cur;
            reverse(cur.begin(),cur.end());
            if(oddcnt>0)temp+=oddch+cur;
            else temp+=cur;
            if(temp>target && temp<ans)ans=temp;
            return;
        }
        string pref=target.substr(0,idx+1);
        for(int i=0;i<nums.size();++i)
        {
            if(nums[i]>0)
            {
                char ch='a'+i;
                string temp=cur+ch;
                nums[i]--;
                if(pref<=temp)recur(nums,target,idx+1,temp,len,ans,oddch,oddcnt,st,mx);
                nums[i]++;
            }
        }
        st.insert(p);
    }
    string lexPalindromicPermutation(string s, string target) {
        vector<int>cnt(26,0);
        set<pair<int,string>>st;
        for(int i=0;i<s.length();++i)cnt[s[i]-'a']++;
        int oddcnt=0;
        char oddch='a';
        for(int i=0;i<cnt.size();++i)
        {
            if(cnt[i]%2)
            {
                oddch+=i;
                oddcnt++;
                cnt[i]--;
            }
            cnt[i]/=2;
        }
        if((s.length()%2==0 && oddcnt>=1) || (s.length()%2==1 && oddcnt>1))return "";
        string ans(302,'z');
        string mx=ans;
        recur(cnt,target,0,"",s.length()/2,ans,oddch,oddcnt,st,mx);
        if(ans==mx)return "";
        return ans;
    }
};