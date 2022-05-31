class Solution {
public:
    int largestRectangleArea(vector<int>& heights) {
        stack<int> s;
        int res=0, curr=0, n=heights.size();
        for(int i=0;i<n;i++) {
            
            while(!s.empty() && heights[s.top()]>heights[i]) {
                int top = heights[s.top()];
                s.pop();
                curr = top*(s.empty()?i:(i-1-s.top()));
                res = max(res, curr);
            }
            
            s.push(i);
        }
        
        while(!s.empty()) {
            int top = heights[s.top()];
            s.pop();
            curr = top*(s.empty()?n:(n-s.top()-1));
            res = max(res, curr);
        }
        
        return res;
    }
};