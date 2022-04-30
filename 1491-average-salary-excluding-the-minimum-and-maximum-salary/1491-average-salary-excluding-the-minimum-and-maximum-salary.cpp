class Solution {
public:
    double average(vector<int>& salary) {
        int mx = INT_MIN, mn = INT_MAX, sum=0;
        for(int i=0;i<salary.size();i++) {
            mx = max(mx, salary[i]);
            mn = min(mn, salary[i]);
            sum+=salary[i];
        }
        
        return (double)(sum-mx-mn)/(double)(salary.size()-2);
    }
};