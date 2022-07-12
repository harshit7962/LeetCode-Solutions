class Solution {
public:
    int numBusesToDestination(vector<vector<int>>& routes, int source, int target) {
        if(source == target) return 0;
        vector<int> adj[routes.size()];
        
        unordered_map<int, vector<int>> mp;
        
        queue<pair<int, int>> q;
        vector<bool> tar(routes.size(), false), vis(routes.size(), false);
        
        for(int i=0;i<routes.size();i++) {
            for(int j:routes[i]) {
                if(j==source) {q.push({i, 0}); vis[i] = true;}
                if(j==target) tar[i] = true;
                mp[j].push_back(i);
            }
        }
        
        
        //Making our graph
        int sz;
        for(auto x:mp) {
            sz = x.second.size();
            if(sz>1) {
                for(int i=0;i<sz;i++) {
                    for(int j=i+1;j<sz;j++) {
                        adj[x.second[i]].push_back(x.second[j]);
                        adj[x.second[j]].push_back(x.second[i]);
                    }
                }
            }
        }
        
        
        while(!q.empty()) {
            int node = q.front().first;
            int dis = q.front().second;
            
            q.pop();
            
            if(tar[node]) {
                return dis+1;
            }
            
            for(int j:adj[node]) {
                if(!vis[j]) {
                    vis[j] = true;
                    q.push({j, dis+1});
                }
            }
        }
        
        return -1;
    }
};