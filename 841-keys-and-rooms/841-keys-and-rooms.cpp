class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        int n = rooms.size();
        vector<bool> visited(n, false);
        
        queue<int> q;
        q.push(0);
        visited[0] = true;
        int count = n-1;
        
        while(!q.empty()) {
            int x = q.front();
            q.pop();
            
            for(int i:rooms[x]) {
                if(!visited[i]) {
                    count--;
                    visited[i] = true;
                    q.push(i);
                }
            }
        }
        
        return (count == 0);
    }
};