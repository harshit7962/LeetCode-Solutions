class Solution {
public:
    int nthUglyNumber(int n) {
        priority_queue<long, vector<long>, greater<long>>pq;
        vector<long> res;
        
        pq.push(1);
        
        while(res.size()<n) {
            long x = pq.top();
            pq.pop();
            if(res.size()!=0 && x==res[res.size()-1]) continue;
            
            res.push_back(x);
            
            pq.push(x*2);
            pq.push(x*3);
            pq.push(x*5);
        }
        
        return res[n-1];
    }
};