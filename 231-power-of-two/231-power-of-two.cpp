class Solution {
public:
    bool isPowerOfTwo(int n) {
        int setNumber=0;
        while(n>0) {
            n = n&(n-1);
            setNumber++;
            if(setNumber>1) return false;
        }
        return setNumber==1;
    }
};