class Solution {
public:
    int largestOverlap(vector<vector<int>>& img1, vector<vector<int>>& img2) {
        int ans=0,n=img1.size(),curr=0;

        for(int row1=0;row1<n;row1++) {
            for(int col1=0;col1<n;col1++) {
                
                curr=0;
                for(int row2=0;row2<n;row2++) {
                    for(int col2=0;col2<n;col2++) {
                        if((row2+row1)<n && (col1+col2)<n && img2[row2+row1][col2+col1]==1 && img2[row2+row1][col2+col1]==img1[row2][col2]) {
                            curr++;
                        }
                    }
                }
                ans=max(ans,curr);

                curr=0;
                for(int row2=0;row2<n;row2++) {
                    for(int col2=0;col2<n;col2++) {
                        if((row2+row1)<n && (col1+col2)<n && img1[row2+row1][col2+col1]==1 && img1[row2+row1][col2+col1]==img2[row2][col2]) {
                            curr++;
                        }
                    }
                }
                ans=max(ans,curr);

                curr=0;
                for(int row2=0;row2<n;row2++) {
                    for(int col2=0;col2<n;col2++) {
                        if((row2+row1)<n && (col2-col1)>=0 && img1[row2+row1][col2-col1]==1 && img1[row2+row1][col2-col1]==img2[row2][col2]) {
                            curr++;
                        }
                    }
                }
                ans=max(ans,curr);

                curr=0;
                for(int row2=0;row2<n;row2++) {
                    for(int col2=0;col2<n;col2++) {
                        if((row2-row1)>=0 && (col2+col1)<n && img1[row2-row1][col2+col1]==1 && img1[row2-row1][col2+col1]==img2[row2][col2]) {
                            curr++;
                        }
                    }
                }
                ans=max(ans,curr);

                curr=0;
                for(int row2=0;row2<n;row2++) {
                    for(int col2=0;col2<n;col2++) {
                        if((row2-row1)>=0 && (col2-col1)>=0 && img1[row2-row1][col2-col1]==1 && img1[row2-row1][col2-col1]==img2[row2][col2]) {
                            curr++;
                        }
                    }
                }
                ans=max(ans,curr);
            }
        }


        return ans;
    }
};