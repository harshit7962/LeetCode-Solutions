class Solution {
public:
    int findCenter(vector<vector<int>>& res) {
        if(res[0][0]==res[1][0] || res[0][0] == res[1][1]) return res[0][0];
        else return res[0][1];
        return -1;
    }
};