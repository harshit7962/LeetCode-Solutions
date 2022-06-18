class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<int> inDegree(n, 0), outDegree(n, 0);
        
        for(auto v: trust) {
            inDegree[v[1]-1]++;
            outDegree[v[0]-1]++;
        }
        
        for(int i=0;i<n;i++) {
            if(outDegree[i]==0 && inDegree[i]==n-1) return i+1;
        }
        
        return -1;
    }
};