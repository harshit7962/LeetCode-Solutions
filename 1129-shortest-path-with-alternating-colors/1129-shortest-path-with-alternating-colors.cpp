class Solution {
public:
    
    vector<int> bfs(vector<int> redAdj[], vector<int> blueAdj[], int n) {
        vector<int> distance(n, -1);
        distance[0] = 0;
        
        queue<pair<int, char>> q;
        vector<bool> redVisited(n, false), blueVisited(n, false);
        
        int dist=1;
        for(int y:redAdj[0]) {
            q.push({y, 'R'});
            redVisited[y] = true;
        }
        
        for(int y:blueAdj[0]) {
            q.push({y, 'B'});
            blueVisited[y] = true;
        }
        
        while(!q.empty()) {
            int c = q.size();
            for(int i=0;i<c;i++) {
                
                int currNode = q.front().first;
                char color = q.front().second;
                
                q.pop();
                
                if(distance[currNode]==-1) distance[currNode] = dist;

                if(color=='R') {
                    for(int y:blueAdj[currNode]) {
                        if(!blueVisited[y]) {
                            q.push({y, 'B'});
                            blueVisited[y] = true;
                        }
                    }
                } else {
                    for(int y:redAdj[currNode]) {
                        if(!redVisited[y]) {
                            q.push({y, 'R'});
                            redVisited[y] = true;
                        }
                    }
                }

            }
            dist++;            
        }
        return distance;
    }
    
    vector<int> shortestAlternatingPaths(int n, vector<vector<int>>& redEdges, vector<vector<int>>& blueEdges) {
        vector<int> redAdj[n], blueAdj[n];
        
        for(int i=0;i<redEdges.size();i++) redAdj[redEdges[i][0]].push_back(redEdges[i][1]);
        for(int i=0;i<blueEdges.size();i++) blueAdj[blueEdges[i][0]].push_back(blueEdges[i][1]);
        
        return bfs(redAdj, blueAdj, n);
    }
};