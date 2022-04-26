class Solution {
public:
    bool isSelfDividing(int n) {
        int d = n;
        while(n>0) {
            if(n%10==0) return false;
            else if(d%(n%10)!=0) return false;
            else n/=10;
        }
        return true;
    }
    
    vector<int> selfDividingNumbers(int left, int right) {
        vector<int> res;
        for(int i=left;i<=right;i++) {
            if(isSelfDividing(i)) res.push_back(i);
        }
        return res;
    }
};