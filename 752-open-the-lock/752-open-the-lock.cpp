class Solution {
public:
    int openLock(vector<string>& deadends, string target) {
        unordered_set<string> deads, visited;
        for(string d:deadends) deads.insert(d);
        if(deads.count("0000")!=0) return -1;
        if(target=="0000") return 0;
        
        visited.insert("0000");
        
        queue<pair<string, int>> q;
        q.push({"0000", 0});
        
        while(!q.empty()) {
            string curr_val = q.front().first;
            int num_turns = q.front().second;
            q.pop();
            
            string next_val;
            
            for(int i=0;i<4;i++) {
                char c1 = curr_val[i];
                
                //Moving it one step behind
                char c = (c1=='0')?'9':c1-1;
                next_val = curr_val.substr(0,i) + c + curr_val.substr(i+1);
                if(deads.count(next_val)==0 && visited.count(next_val)==0) {
                    if(next_val==target) return num_turns+1;
                    visited.insert(next_val);
                    q.push({next_val, num_turns+1});
                }
                
                //Moving it one step forward
                c = (c1=='9')?'0':c1+1;
                next_val = curr_val.substr(0,i) + c + curr_val.substr(i+1);
                if(deads.count(next_val)==0 && visited.count(next_val)==0) {
                    if(next_val==target) return num_turns+1;
                    visited.insert(next_val);
                    q.push({next_val, num_turns+1});
                }
            }
        }
        
        return -1;
    }
};