class Solution {
public:
    vector<int> findSmallestSetOfVertices(int n, vector<vector<int>>& edges) {
        vector<int> inDegree(n, 0);
        
        for(auto v:edges) {
            inDegree[v[1]]++;
        }
        
        vector<int> res;
        for(int i=0;i<n;i++) if(inDegree[i]==0) res.push_back(i);
        
        return res;
    }
};