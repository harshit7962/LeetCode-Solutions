class Solution {
public:
    int sum(vector<int> arr, int i, int j) {
        int res=0;
        for(int x=i;x<=j;x++) res+=arr[x];
        return res;
    }
    
    int sumOddLengthSubarrays(vector<int>& arr) {
        int res=0;
        for(int i=0;i<arr.size();i++) {
            for(int j=i;j<arr.size();j++) {
                if((i+j)%2==0) res+=sum(arr, i, j);
            }
        }
        return res;
    }
};