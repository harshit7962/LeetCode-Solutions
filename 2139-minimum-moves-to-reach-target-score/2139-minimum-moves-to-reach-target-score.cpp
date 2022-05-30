class Solution {
public:
    int minMoves(int target, int maxDoubles) {
        int res = 0;
        while(maxDoubles!=0 && target!=1) {
            if(target&1) {
                target--;
                res++;
            } else {
                res++;
                target/=2;
                maxDoubles--;
            }
        }
        
        return res + (target-1);
    }
};