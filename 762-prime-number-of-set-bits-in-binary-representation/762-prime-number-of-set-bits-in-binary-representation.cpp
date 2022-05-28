class Solution {
public:
    bool isPrime(int num) {
        if(num==0 || num==1) return false;
        for(int i=2;i<=sqrt(num);i++) {
            if(num%i==0) return false;
        }
        
        return true;
    }
    
    int kSet(int num) {
        int res=0;
        while(num>0) {
            res++;
            num=num&(num-1);
        }
        
        return res;
    }
    
    int countPrimeSetBits(int left, int right) {
        int count=0;
        for(int i=left;i<=right;i++) {
            if(isPrime(kSet(i))) count++;
        }
        cout << endl;
        return count;
    }
};