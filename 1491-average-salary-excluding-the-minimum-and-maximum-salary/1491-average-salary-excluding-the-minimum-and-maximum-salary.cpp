class Solution {
public:
    double average(vector<int>& salary) {
        double mx = INT_MIN, mn = INT_MAX, sum=0;
        for(int i=0;i<salary.size();i++) {
            if(mx<salary[i]) mx = salary[i];
            if(mn>salary[i]) mn = salary[i];
            
            sum+=salary[i];
        }
        return (sum-mx-mn)/(salary.size()-2);
    }
};