class Solution {
public:
    static int numOfSetBits(int n) {
        int res=0;
        while(n>0) {
            n=n&(n-1);
            res++;
        }
        return res;
    }
    
    static bool comparision(int a, int b) {
        if(numOfSetBits(a)==numOfSetBits(b)) return (a<b);
        return (numOfSetBits(a) < numOfSetBits(b));
    }
    
    vector<int> sortByBits(vector<int>& arr) {
        sort(arr.begin(), arr.end(), comparision);
        return arr;
    }
};