class Solution {
public:
    int reverse(int x) {
        int b=0;
        while(x) {
            if(b>INT_MAX/10 || b<INT_MIN/10) return 0;
            b = b*10+x%10;
            x/=10;
        }

        return b;
    }
};