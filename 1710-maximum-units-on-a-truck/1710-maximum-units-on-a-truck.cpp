class Solution {
public:
    static bool myCmp(vector<int> &v1,  vector<int> &v2) {
        return v1[1]>v2[1];
    }
    
    int maximumUnits(vector<vector<int>>& boxTypes, int truckSize) {
        sort(boxTypes.begin(), boxTypes.end(), myCmp);
        
        int i=0, res=0;
        
        while(i<boxTypes.size() && truckSize>0) {
            if(truckSize>boxTypes[i][0]) {
                res+=boxTypes[i][0]*boxTypes[i][1];
                truckSize-=boxTypes[i][0];
            } else {
                res+=truckSize*boxTypes[i][1];
                break;
            }
            i++;
        }
        
        return res;     
    }
};