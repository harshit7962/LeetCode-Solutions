class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> temp, curr;
        temp.push_back(1);
        curr.push_back(1);
        for(int i=1;i<=rowIndex;i++) {
            curr.clear();
            curr.push_back(1);
            for(int j=1;j<i;j++){
                curr.push_back(temp[j-1]+temp[j]);
            }
            curr.push_back(1);
            temp = curr;
        }
        
        return curr;
    }
};