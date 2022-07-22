class Solution {
public:
    int sumDigits(int num) {
        int res = 0;
        while(num>0) {
            res += num%10;
            num /= 10;
        }
        
        return res;
    }
    
    int addDigits(int num) {
        while(num>9) {
            num = sumDigits(num);
        }
        
        return num;
    }
};