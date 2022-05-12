class Solution {
public:
    bool isPalindrome(int x) {
        long long int d = x, b=0;
        while(d>0) {
            b=b*10+(d%10);
            d/=10;
        }
        return b==x;
    }
};