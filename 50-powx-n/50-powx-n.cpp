class Solution {
public:
    double myPow(double x, int n) {
        double ans = 1.0;
        long int d = abs(n);
        
        while(d>0) {
            if(d&1) {
                ans = ans*x;
            }
            d = d/2;
            x = x*x;
        }
        
        if(n<0) return 1.0/ans;
        return ans;
    }
};