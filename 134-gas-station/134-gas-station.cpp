class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_pet = 0, total_dis = 0;
        
        for(int i=0;i<gas.size();i++) {
            total_pet += gas[i];
            total_dis += cost[i];
        }
        
        if(total_pet<total_dis) return -1;
        
        int curr_pet=0, start=0, curr=0;
        
        while(curr<gas.size()) {
            curr_pet += gas[curr];
            
            int nxt = cost[curr];
            
            if(nxt>curr_pet) {
                curr_pet =0;
                start = curr+1;
            } else {
                curr_pet -= nxt;
            }
            
            curr++;
        }
        
        return start;
    }
};