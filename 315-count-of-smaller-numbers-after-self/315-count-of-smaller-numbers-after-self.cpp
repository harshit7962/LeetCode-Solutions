// class Solution {
// public:
    
//     void merge(vector<int>&count, vector<pair<int, int>> &v, int left, int mid, int right) {
//         int i = left, j = mid+1, k=0;
//         vector<pair<int,int>> temp(right-left+1);
        
//         while(i<=mid &&  j<=right) {
//             if(v[i].first <= v[j].first) {
//                 temp[k] = v[j];
//                 k++;
//                 j++;
//             } else {
//                 //If the right value is lesser, we append the count to result as well...
//                 count[v[i].second] += right-j+1;
//                 temp[k] = v[i];
//                 k++;
//                 i++;
//             }
//         }
        
//         while(i<=mid) temp[k++] = v[i++];
//         while(j<=right) temp[k++]  = v[j++];
        
//         for(int i=left;i<right;i++) v[i] = temp[i-left];
//     }
    
//     void mergeSort(vector<int>&count, vector<pair<int, int>> &v, int left, int right) {
//         //Simple merge sort function to sort left half and right half and then merge them
//         if(left < right) {
//             int mid = left + (right - left)/2;
//             mergeSort(count, v, left, mid);
//             mergeSort(count, v, mid+1, right);
//             merge(count, v, left, mid, right);
//         }
//     }
    
//     vector<int> countSmaller(vector<int>& nums) {
//         int n = nums.size();
        
//         //We are creating a vector of  pairs, to store element and its index... (index to count inversions)
//         vector<pair<int, int>> v(n);
//         for(int i=0;i<n;i++) v[i] = {nums[i], i};
        
//         //Result  variable to store counts of each inversion
//         vector<int> count(n, 0);
        
//         mergeSort(count, v, 0, n-1);
        
//         return count;
//     }
// };
class Solution {
public:
    
    void merge(vector<int> &count, vector<pair<int, int>> &v, int left, int mid, int right){
        vector<pair<int,int>> temp(right - left + 1);
        int i=left;
        int j=mid+1;
        int k=0;
        
        while(i<=mid && j<=right){
            
            if(v[i].first <= v[j].first){
                temp[k++] = v[j++];
            }
            
            else{
                
                count[v[i].second] += right-j+1;
                temp[k++] = v[i++];
                
            }
            
        }
        
        
        while(i<=mid){
            temp[k++] = v[i++];
        }
        
        while(j<=right){
            temp[k++] = v[j++];
        }
        
        for(int i=left;i<=right;i++){
            v[i] = temp[i-left]; 
        }
        
    }
    
    void mergeSort(vector<int> &count, vector<pair<int,int>> &v, int left, int right){
        
        
        if(left<right){
            int mid = left + (right-left)/2;
            mergeSort(count, v, left, mid);
            mergeSort(count, v, mid+1, right);
            merge(count, v, left, mid, right);
        }
        
    }
    
    vector<int> countSmaller(vector<int>& nums) {
        int n = nums.size();
        vector<pair<int,int>> v(n);
        for(int i=0;i<n;i++){
            pair<int, int> p;
            p.first = nums[i];
            p.second = i;
            v[i] = p;
        }
        
        
        vector<int> count(n, 0);
        mergeSort(count, v, 0, n-1);
        return count;
        
    }
};