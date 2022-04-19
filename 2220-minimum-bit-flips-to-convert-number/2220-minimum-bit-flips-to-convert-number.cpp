class Solution {
public:
    int setBits(int num) {
        int res=0;
        while(num>0) {
            num = num & (num-1);
            res++;
        }
        return res;
    }
    
    int minBitFlips(int start, int goal) {
        return setBits(start^goal);
    }
};