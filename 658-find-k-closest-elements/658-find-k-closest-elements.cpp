class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        priority_queue<pair<int, int>> pq;
        
        for(int i=0;i<k;i++) {
            pq.push({abs(x-arr[i]), arr[i]});
        }
        
        for(int i=k;i<arr.size();i++) {
            if(abs(arr[i]-x) <= pq.top().first) {
                pq.push({abs(arr[i]-x), arr[i]});
                pq.pop();
            }
        }
        
        vector<int> res;
        
        while(!pq.empty()) {
            res.push_back(pq.top().second);
            pq.pop();
        }
        
        sort(res.begin(), res.end());
        
        return res;
    }
};