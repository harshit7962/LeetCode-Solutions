class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        if(n==0) return tasks.size();
        
        vector<int> char_map(26, 0);
        
        for(char c:tasks) char_map[c-'A']++;
        
        priority_queue<int> pq;
        queue<pair<int, int>> q;
        
        for(int i:char_map) if(i!=0) pq.push(i);
        
        int curr_time = 0;
        
        while(!pq.empty() || !q.empty()) {
            curr_time++;
            
            //If at a given time, front of the queue has passed cooldown time, we add it to priority list
            if(!q.empty() && q.front().second <= curr_time) {
                pq.push(q.front().first);
                q.pop();
            }
            
            //If there is any task in our waiting priority queue, we do the following
            if(!pq.empty()) {
                //Pop the number of occurance of that task
                int num_tasks = pq.top();
                pq.pop();
            
                //If that task is still left, push it into waiting queue with cooldown time
                if(num_tasks>1)
                q.push({num_tasks-1, n+curr_time+1});
            }
        }
        
        return curr_time;
    }
};