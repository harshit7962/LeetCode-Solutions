class Solution {
public:
    vector<vector<int>> construct2DArray(vector<int>& original, int m, int n) {
        if(m*n!=original.size()) return {};
        
        vector<vector<int>> res;
        
        vector<int> curr;
        
        for(int i=0;i<original.size();i++) {
            if(i!=0 && i%n==0) {
                res.push_back(curr);
                curr = {};
            }
            
            curr.push_back(original[i]);
        }
        res.push_back(curr);
        return res;
    }
};