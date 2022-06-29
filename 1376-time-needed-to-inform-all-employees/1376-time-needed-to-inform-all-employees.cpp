class Solution {
public:
    
    int final_res = INT_MAX;
    
    int bfs(vector<int> adj[], vector<int> informTime, int src) {
        queue<pair<int, int>> q;
        q.push({src, informTime[src]});
        
        int res=0;
        
        while(!q.empty()) {
            int node = q.front().first;
            int time = q.front().second;
            
            q.pop();
            res = max(res, time);
            
            for(int subordinates: adj[node]) {
                q.push({subordinates, time+informTime[subordinates]});
            }
        }
        
        return res;
    }
    
    int numOfMinutes(int n, int headID, vector<int>& manager, vector<int>& informTime) {
        if(n==1) return  0;
        vector<int> adj[n];
        
        for(int i=0;i<manager.size();i++) {
            if(manager[i]!=-1) {
                adj[manager[i]].push_back(i);
            }
        }
        
        return bfs(adj, informTime, headID);
    }
};