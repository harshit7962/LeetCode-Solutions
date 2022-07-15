class Solution {
public:
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> res(n, -1);
        res[0] = 0;
        
        queue<pair<int, char>> q;
        vector<bool> redVisited(n, false), blueVisited(n, false);
        
        vector<int> redAdj[n], blueAdj[n];
        
        for(auto v: redEdges) {
            redAdj[v[0]].push_back(v[1]);
        }
        for(auto v:blueEdges) {
            blueAdj[v[0]].push_back(v[1]);
        }
        
        for(int i:redAdj[0]){
            q.push({i, 'R'});
            redVisited[i] = true;
        }
        
        for(int i:blueAdj[0]) {
            q.push({i, 'B'});
            blueVisited[i] = true;
        }
        
        int dist = 1;
        while(!q.empty()) {
            int c = q.size();
            for(int i=0;i<c;i++) {
                int node = q.front().first;
                char col = q.front().second;
                
                q.pop();
                
                if(res[node]==-1) res[node] = dist;
                
                if(col == 'B') {
                    for(int y:redAdj[node]) {
                        if(!redVisited[y]) {
                            q.push({y, 'R'});
                            redVisited[y] = true;
                        }
                    }
                } else {
                    for(int y:blueAdj[node]) {
                        if(!blueVisited[y]) {
                            q.push({y, 'B'});
                            blueVisited[y] = true;
                        }
                    }
                }
                
            }
            
            dist++;
        }
        
        return res;
    }
};