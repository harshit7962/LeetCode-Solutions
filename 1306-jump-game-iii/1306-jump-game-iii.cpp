class Solution {
public:
    bool canReach(vector<int>& arr, int start) {
        if(arr[start]==0) return true;
        int n=arr.size();
        vector<bool> visited(n, false);
        visited[start] = true;
        
        queue<int> q;
        q.push(start);
        
        while(!q.empty()) {
            int curr = q.front();
            q.pop();
            
            int fwd_ind = arr[curr]+curr, bck_ind = curr - arr[curr];
            if(fwd_ind<n && !visited[fwd_ind]) {
                if(arr[fwd_ind]==0) return true;
                q.push(fwd_ind);
                visited[fwd_ind] = true;
            }
            if(bck_ind>=0 && !visited[bck_ind]) {
                if(arr[bck_ind]==0) return true;
                q.push(bck_ind);
                visited[bck_ind] = true;
            }
        }
        
        
        return false;
    }
};