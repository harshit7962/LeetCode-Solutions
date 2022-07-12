class Solution {
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> adj[numCourses];
        
        vector<int> res, indegree(numCourses, 0);
        
        for(vector v:prerequisites) {
            adj[v[1]].push_back(v[0]);
            indegree[v[0]]++;
        }
        
        queue<int> q;
        for(int i=0;i<numCourses;i++) {
            if(indegree[i]==0) {q.push(i);}
        }
        
        while(!q.empty()) {
            int node = q.front();
            q.pop();
            res.push_back(node);
            
            for(int i:adj[node]) {
                indegree[i]--;
                if(indegree[i]==0) q.push(i);
            }
        }
        
        if(res.size()!=numCourses) return {};
        
        return res;
    }
};