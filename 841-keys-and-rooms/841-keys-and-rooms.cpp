class Solution {
public:
    bool canVisitAllRooms(vector<vector<int>>& rooms) {
        vector<int> visited(rooms.size(), false);
        visited[0]=true;
        queue<int> q;
        q.push(0);
        while(!q.empty()) {
            int room = q.front();
            q.pop();
            for(int keys:rooms[room]) {
                if(!visited[keys]) {
                    q.push(keys);
                    visited[keys]=true;
                }
            }
        }
        
        for(auto x:visited) if(!x) return false;
        return true;
    }
};