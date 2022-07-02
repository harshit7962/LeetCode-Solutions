class Solution {
public:    
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> visited, list;
        
        for(string s:wordList) list.insert(s);
        
        visited.insert(beginWord);
        
        queue<pair<string, int>> q;
        q.push({beginWord, 1});
        
        while(!q.empty()) {
            string curr = q.front().first;
            int steps = q.front().second;
            
            q.pop();
            
            for(int i=0;i<curr.size();i++) {
                char x = curr[i];
                for(char c='a';c<='z';c++) {
                    curr[i] = c;
                    
                    if(list.count(curr)==1 && visited.count(curr)==0) {
                        if(curr==endWord) return steps+1;
                        visited.insert(curr);
                        q.push({curr, steps+1});
                    }
                }
                curr[i] = x;
            }
        }
        
        return 0;        
    }
};