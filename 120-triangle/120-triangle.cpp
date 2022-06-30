class Solution {
public:
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1) return triangle[0][0];
        int res=INT_MAX;
        
        vector<int> prev=triangle[0], curr;
        for(int i=1;i<triangle.size();i++) {
            curr = triangle[i];
            
            for(int j=0;j<curr.size();j++) {
                
                int min_val;
                if(j==0) {
                    min_val = prev[0];
                } else if(j==curr.size()-1) {
                    min_val = prev[curr.size()-2];
                } else {
                    min_val = min(prev[j], prev[j-1]);
                }
                
                curr[j]+=min_val;
            }
            prev = curr;
        }
        
        for(int i:curr) res = min(res, i);
        
        return res;
    }
};