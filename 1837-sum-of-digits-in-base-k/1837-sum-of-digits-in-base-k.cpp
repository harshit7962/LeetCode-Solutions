class Solution {
public:
    int sum(int x) {
        int res=0;
        while(x>0) {
            res+=x%10;
            x/=10;
        }
        return res;
    }
    
    int sumBase(int n, int k) {
        if(k==10) return sum(n);
        int x=0;
        while((n/k)!=0) {
            x=x*10+(n%k);
            n/=k;
        }
        x=x*10+n;
        return sum(x);
    }
};