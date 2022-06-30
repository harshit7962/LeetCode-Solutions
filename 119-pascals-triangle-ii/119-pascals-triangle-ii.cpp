class Solution {
public:
    vector<int> getRow(int rowIndex) {
        if(rowIndex==0) return {1};
        
        vector<int> prev, curr;
        prev.push_back(1);
        
        while(rowIndex>0) {
            curr.clear();
            curr.push_back(1);
            for(int i=1;i<prev.size();i++) curr.push_back(prev[i]+prev[i-1]);
            curr.push_back(1);
            prev = curr;
            rowIndex--;
        }
        
        return curr;
    }
};