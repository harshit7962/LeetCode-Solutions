class Solution {
public:
    vector<vector<int>> reconstructQueue(vector<vector<int>>& people) {
        //sorting our array
        sort(people.begin(), people.end());
        
        //initializing our auxilary array
        vector<vector<int>> res(people.size(), {-1,-1});
        
        //Programming logic
        for(int i=0;i<people.size();i++) {
            int counter = people[i][1], j=0;
            
            while(counter!=0) {
                if(res[j][0]==-1 || res[j][0]==people[i][0]) counter--;
                j++;
            }
            
            while(res[j][0]!=-1) j++;
            
            res[j] = people[i];
        }
        
        //return our initialized array
        return res;
    }
};