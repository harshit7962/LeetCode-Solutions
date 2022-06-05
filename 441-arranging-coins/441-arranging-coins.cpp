class Solution {
public:
    int arrangeCoins(int n) {
        int rows=1;
        n--;
        while(n>0) {
            rows++;
            n-=rows;
        }
        
        if(n==0) return rows;
        return rows-1;
    }
};