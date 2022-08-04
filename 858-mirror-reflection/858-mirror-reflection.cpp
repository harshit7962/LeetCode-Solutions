class Solution {
public:
    int mirrorReflection(int p, int q) {
        if(q==0) return 0;
        int g = gcd(p,q);
        int lc = p*q/g;
        if((lc/q)%2 == 0){
            return 2;
        } else {
            return (lc/p)%2 == 0 ? 0 : 1;
        }
    }
};