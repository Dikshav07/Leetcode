class Solution {
public:
    int daysPassed(string s)
    {
        int m=stoi(s.substr(0,2));
        int d=stoi(s.substr(3,2));
        vector<int>a={0,31,28,31,30,31,30,31,31,30,31,30,31};
        for(int i=1;i<m;++i)d+=a[i];
        return d;
    }
    int countDaysTogether(string arriveAlice,string leaveAlice,string arriveBob,string leaveBob)
    {
        int l=max(daysPassed(arriveAlice),daysPassed(arriveBob));
        int r=min(daysPassed(leaveAlice),daysPassed(leaveBob));
        return max(0,r-l+1);
    }
};