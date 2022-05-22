class Solution {
public:
    int minimumLines(vector<vector<int>>& stk) {
        sort(stk.begin(),stk.end());
        int n = stk.size();
        if(n==1)
            return 0;
        int lines=1;
        long double currSlope = (long double)(stk[1][1]-stk[0][1])/(long double)(stk[1][0]-stk[0][0]);
        for(int i=2;i<n;i++) {
            long double newSlope = (long double)(stk[i][1]-stk[i-1][1])/(long double)(stk[i][0]-stk[i-1][0]);
            if(newSlope!=currSlope) {
                lines++;
                currSlope=newSlope;
            }
        }
        return lines;
    }
};