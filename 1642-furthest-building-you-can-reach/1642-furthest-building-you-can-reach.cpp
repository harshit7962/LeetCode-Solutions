class Solution {
public:
    int furthestBuilding(vector<int>& heights, int bricks, int ladders) {
        int i=0;
        priority_queue<int, vector<int>, greater<int>> pq;
        
        while(ladders>pq.size() && i<heights.size()-1) {
            if(heights[i]<heights[i+1]) pq.push(heights[i+1]-heights[i]);
            i++;
        }

        while(bricks>=0 && i<heights.size()-1) {
            if(heights[i]<heights[i+1]) {
                int diff = heights[i+1]-heights[i];
                if(!pq.empty() && pq.top()<diff) {
                    bricks-=pq.top();
                    pq.pop();
                    pq.push(diff);
                } else {
                    bricks-=diff;
                }
            }
            i++;
        }
        
        
        return bricks>=0?i:i-1;
    }
};