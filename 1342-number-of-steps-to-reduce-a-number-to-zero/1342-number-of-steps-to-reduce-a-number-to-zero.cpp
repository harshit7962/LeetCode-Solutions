class Solution {
public:
    int numberOfSteps(int num) {
        int step=0;
        while(num>0) {
            if(num&1) num-=1;
            else num/=2;
            step++;
        }
        
        return step;
    }
};