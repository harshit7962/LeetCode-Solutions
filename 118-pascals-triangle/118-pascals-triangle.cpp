class Solution {
public:
    vector<vector<int>> generate(int n) {
        vector<vector<int>> res;
        res.push_back({1});
        
        for(int i=1;i<n;i++){
            vector<int> temp(i+1);
            temp[0]=temp[i]=1;
            for(int j=1;j<i;j++) {
                temp[j] = res[i-1][j]+res[i-1][j-1];
            }
            res.push_back(temp);
        }
        
        return res;
    }
};