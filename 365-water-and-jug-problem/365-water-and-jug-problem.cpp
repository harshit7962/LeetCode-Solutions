class Solution {
public:
    bool canMeasureWater(int jug1, int jug2, int target) {
        if(target==jug1 || target==jug2 || target==jug1+jug2) return true;
        if(target>jug1+jug2) return false;
        
        vector<bool> visited(jug1+jug2+1, false);
        queue<int> q;
        q.push(0);
        visited[0]=true;
        
        while(!q.empty()) {
            int x =  q.front();
            q.pop();
            if(x == target) return true;
            
            //We can remove jug1 amount of water
            if(x-jug1>=0 && !visited[x-jug1]) {
                visited[x-jug1] = true;
                q.push(x-jug1);
            } 
            
            //We can add jug1 amount of water
            if(x+jug1<=jug1+jug2 && !visited[x+jug1]) {
                visited[x+jug1] = true;
                q.push(x+jug1);
            }
            
            //We can remove jug2 amount of water
            if(x-jug2>=0 && !visited[x-jug2]) {
                visited[x-jug2] = true;
                q.push(x-jug2);
            }
            
            //We can add jug2 amount of water
            if(x+jug2<=jug1+jug2 && !visited[x+jug2]) {
                visited[x+jug2] = true;
                q.push(x+jug2);
            }
        }
        
        return false;        
    }
};