class Solution {
public:
    int arrangeCoins(int n) {
        int left=1, right=n, res=0;
        
        while(left<=right) {
            long long mid = left + (right-left)/2;
            
            long long coins = mid*(mid+1)/2;
            
            if(coins==n) return mid;
            else if(coins>n) right = mid-1;
            else {
                res = mid;
                left = mid+1;
            }
        }
        
        return res;
    }
};