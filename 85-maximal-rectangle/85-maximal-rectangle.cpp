class Solution {
public:
    int largestHist(vector<int> nums) {
        int res=0;
        stack<int> s;
        for(int i=0;i<nums.size();i++) {
            while(!s.empty() && nums[s.top()]>nums[i]) {
                int tp = nums[s.top()];
                s.pop();
                int curr =  tp*(s.empty()?i:i-1-s.top());
                res = max(curr, res);
            }
            s.push(i);
        }
        
        while(!s.empty()) {
            int  tp = nums[s.top()];
            s.pop();
            int curr = tp*(s.empty()?nums.size():nums.size()-s.top()-1);
            res = max(curr, res);
        }
        
        return res;
    }
    
    
    int maximalRectangle(vector<vector<char>>& matrix) {
        
        vector<vector<int>> mat(matrix.size(), vector<int>(matrix[0].size()));
        
        
        for(int i=0;i<matrix.size();i++) {
            for(int j=0;j<matrix[0].size();j++) {
                mat[i][j] = matrix[i][j]-'0';
            }
        }
        
        int res = largestHist(mat[0]);
        
        for(int i=1;i<mat.size();i++) {
            for(int j=0;j<mat[0].size();j++){
                if(mat[i][j]==1)
                mat[i][j]+=mat[i-1][j];
            }
            
            res = max(res, largestHist(mat[i]));
        }
        
        return res;
    }
};