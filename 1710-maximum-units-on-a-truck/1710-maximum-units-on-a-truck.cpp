class Solution {
public:
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        map<int, int, greater<int>> mp;
        
        for(int i=0;i<boxTypes.size();i++) mp[boxTypes[i][1]]+=boxTypes[i][0];
        
        int res=0;
        for(auto i:mp) {
            if(i.second < truckSize) {
                res+=(i.first*i.second);
                truckSize-=i.second;
            } else if(i.second >= truckSize) {
                res+=(truckSize*i.first);
                return res;
            }
        }
        return res;
    }
};