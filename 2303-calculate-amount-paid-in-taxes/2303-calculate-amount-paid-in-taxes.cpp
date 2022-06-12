class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        if(income==0) return 0.0;
        double total_tax=0;
        int prev=0;
        
        for(vector v:brackets) {
            int curr_val = v[0]-prev;
            if(income > curr_val) {
                income-=curr_val;
                total_tax+=(double)curr_val*(double)v[1]/100;
                prev = v[0];
            } else {
                total_tax+=(double)income*(double)v[1]/100;
                break;
            }
        }
        
        return total_tax;
    }
};