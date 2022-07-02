class Solution {
public:
    
    int dist(string s, string t) {
        int res=0;
        for(int i=0;i<8;i++) if(s[i]!=t[i]) res++;
        return res;
    }
    
    int minMutation(string start, string end, vector<string>& bank) {
        vector<bool> visited(bank.size(), false);
        queue<pair<string, int>> q;
        q.push({start,0});
        
        while(!q.empty()) {
            string curr = q.front().first;
            int num_mutations = q.front().second;
            q.pop();
            
            for(int i=0;i<bank.size();i++) {
                if(!visited[i] && dist(curr, bank[i])==1) {
                    if(bank[i] == end) return num_mutations+1;
                    visited[i]  = true;
                    q.push({bank[i], num_mutations+1});
                }
            }
        }
        
        return -1;
    }
};