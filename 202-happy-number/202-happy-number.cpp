class Solution {
public:
    int sumOfSquaredDigits(int n) {
        int res=0;
        while(n>0) {
            res+=(n%10)*(n%10);
            n/=10;
        }
        return res;
    }
    
    bool isHappy(int n) {
        map<int, int> mp;
        mp.insert({n,1});
        int curr=sumOfSquaredDigits(n);
        while(curr!=1) {
            if(mp.find(curr)!=mp.end()) return false;
            mp[curr]=1;
            curr=sumOfSquaredDigits(curr);
        }
        return true;
    }
};