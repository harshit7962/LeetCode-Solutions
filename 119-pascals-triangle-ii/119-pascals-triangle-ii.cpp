class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<vector<int>> res;
        res.push_back({1});
        
        for(int i=1;i<=rowIndex;i++) {
            vector<int> temp(i+1, 1);
            for(int j=1;j<i;j++){
                temp[j] =  res[i-1][j-1]+res[i-1][j];
            }
            if(i==rowIndex) return temp;
            res.push_back(temp);
        }
        
        return {1};
    }
};