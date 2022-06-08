class Solution {
public:
    int lastOcc(vector<int> v) {
        int low=0, high=v.size()-1;
        int res=-1;
        while(low<=high){
            int mid = low + (high-low)/2;
            if(v[mid]==0) high = mid-1;
            else {
                res = mid;
                low = mid+1;
            }
        }
        
        return res+1;
    }
    
    vector<int> kWeakestRows(vector<vector<int>>& mat, int k) {
        vector<pair<int, int>> str;
        
        for(int i=0;i<mat.size();i++) {
            str.push_back({lastOcc(mat[i]), i});
        }
        
        sort(str.begin(), str.end());
        
        vector<int> res(k);
        for(int i=0;i<k;i++) res[i] = str[i].second;
        
        return res;
    }
};