class Compare {
public:
    bool operator()(pair<int, string> &p1, pair<int, string> &p2) {
        if(p1.first==p2.first) return p1.second>p2.second;
        
        return p1.first < p2.first;
    }
};


class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        map<string, int> mp;
        
        for(string word:words) mp[word]++;
        
        priority_queue<pair<int, string>, vector<pair<int, string>>, Compare> pq;
        
        for(auto x:mp) pq.push({x.second, x.first});
        
        vector<string> res;
        
        for(int i=0;i<k;i++) {
            string s = pq.top().second;
            
            res.push_back(s);
            pq.pop();
        }
        
        return res;
    }
};