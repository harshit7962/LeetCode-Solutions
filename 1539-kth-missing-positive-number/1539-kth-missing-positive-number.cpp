class Solution {
public:
    int findKthPositive(vector<int>& arr, int k) {
        if(arr[0]>k) return k;
        for(int a:arr) {
            if(a<=k) k++;
            else break;
        }
        
        return k;
    }
};