class Solution {
public:
    bool judgeSquareSum(int c) {
        long long low=0, high=sqrt(c);
        
        while(low<=high) {
            long long res = low*low + high*high;
            if(res == c) return true;
            if(res>c) high--;
            else low++;
        }
        
        return false;
    }
};