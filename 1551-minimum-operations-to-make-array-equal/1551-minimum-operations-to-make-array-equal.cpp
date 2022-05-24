class Solution {
public:
    int minOperations(int n) {
        if(n%2==0) {
            n/=2;
            return n*n;
        }
        n/=2;
        return n*(n+1);
    }
};