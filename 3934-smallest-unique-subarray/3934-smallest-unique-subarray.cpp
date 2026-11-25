class Solution {
public:
    using ull = unsigned long long;
    const ull b = 1000003ULL;
    vector<ull>pw,pref;
    int n;
    void precompute(vector<int>& nums){
        pref.assign(n+1,0);
        pw.assign(n+1,0);
        pw[0] = 1;
        for(int i = 0;i<n;i++){
            pw[i+1] = pw[i] * b;
            pref[i+1] = pref[i]*b + (ull)(nums[i] + 1000007);
        }
    }
    ull fn(int l,int r){
        return pref[r] - pref[l]*pw[r-l];
    }
    bool check(int l){
        int m = n- l + 1;
        vector<ull>h(m);
        for(int i = 0;i<m;i++) h[i] = fn(i,i+l);
        sort(h.begin(),h.end());
        int i = 0;
        while(i<m){
            int j = i;
            while(j<m && h[j] == h[i]) j++;
            if(j - i == 1) return true;
            i = j;
        }
        return false;
    }
    int smallestUniqueSubarray(vector<int>& nums) {
        n = nums.size();
        
        precompute(nums);
        int lo = 1,hi = n;
        while(lo < hi){
            int mid = lo + (hi - lo)/2;
            if(check(mid)) hi = mid;
            else lo = mid + 1;
        }
        return lo;
    }
};