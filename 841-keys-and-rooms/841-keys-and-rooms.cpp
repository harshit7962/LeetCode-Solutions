class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        
        vector<bool> visited(n, false);
        
        queue<int> q;
        q.push(0);
        visited[0]=true;
        
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            for(int y:rooms[x]) {
                if(!visited[y]) {
                    visited[y] = true;
                    q.push(y);
                }
            }
        }
        
        
        for(bool x:visited) if(!x) return x;
        
        return true;
    }
};