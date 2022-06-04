class Solution {
public:
    int mySqrt(int x) {
        int low=0, high=x, res;
        while(low<=high) {
            long long mid = (low+high)/2;
            
            if(mid*mid==x) return mid;
            else if(mid*mid>x) high=mid-1;
            else {
                res = mid;
                low = mid+1;
            }
        }
        
        return res;
    }
};