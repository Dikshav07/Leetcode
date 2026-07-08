class Solution {
public:
    vector<int> sumAndMultiply(string s, vector<vector<int>>& queries) {
        int n=s.length();
        int mod=1e9+7;
        vector<int> pos;
        vector<int> vals;        
        for(int i=0;i<n;++i){
            if(s[i]!='0'){
                pos.push_back(i);
                vals.push_back(s[i]-'0');
            }
        }
        int k=pos.size();
        vector<long long> P(k+1,0);
        vector<long long> S(k+1,0);
        vector<long long> pow10(k+1,1);
        for(int i=1;i<=k;++i){
            P[i]=(P[i-1]*10+vals[i-1])%mod;
            S[i]=S[i-1]+vals[i-1];
            pow10[i]=(pow10[i-1]*10)%mod;
        }
        vector<int> ans;
        ans.reserve(queries.size());
        for(const auto& q:queries){
            int l=q[0];
            int r=q[1];
            auto it1=lower_bound(pos.begin(),pos.end(),l);
            auto it2=upper_bound(pos.begin(),pos.end(),r);
            if(it1==pos.end()||it1>=it2){
                ans.push_back(0);
                continue;
            }
            int left_idx=distance(pos.begin(),it1)+1; 
            int right_idx=distance(pos.begin(),it2);    
            int len=right_idx-left_idx+1;
            long long x=(P[right_idx]-P[left_idx-1]*pow10[len])%mod;
            if(x<0){
                x+=mod;
            }
            long long current_sum=S[right_idx]-S[left_idx-1];
            long long res=(x*current_sum)%mod;
            ans.push_back(res);
        }
        return ans;
    }
};