class Solution {
public:
    int findCenter(vector<vector<int>>& edges) {
        vector<int> v1 = edges[0];
        vector<int> v2 = edges[1];
        for(auto x1:v1) {
            for(auto x2:v2) {
                if(x1==x2) return x1;
            }
        }
        return -1;
    }
};