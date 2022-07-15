class Solution {
public:
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        vector<int> adj[n];
        
        for(int i=0;i<n;i++) {
            if(manager[i]!=-1)
            adj[manager[i]].push_back(i);
        }
        
        
        queue<pair<int, int>> q;
        q.push({headID, informTime[headID]});
        
        int res=0;
        
        while(!q.empty()) {
            int  node = q.front().first;
            int time = q.front().second;
            
            q.pop();
            
            res = max(res, time);
            
            for(int y:adj[node]) {
                q.push({y, time+informTime[y]});
            }
        }
        
        return res;
    }
};