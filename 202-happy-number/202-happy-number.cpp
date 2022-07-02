class Solution {
public:
    int sumofSquares(int n) {
        int res=0;
        while(n>0) {
            res+=(n%10)*(n%10);
            n/=10;
        }
        
        return res;
    }
    
    bool isHappy(int n) {
        unordered_set<int> st;
        
        while(true) {
            int x = sumofSquares(n);
            if(x==1) return true;
            if(st.count(x)>0) return false;
            st.insert(x);
            n=x;
        }
        
        
        return false;
    }
};