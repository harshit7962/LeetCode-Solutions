class Solution {
public:
    double calculateTax(vector<vector<int>>& brackets, int income) {
        if(income<=brackets[0][0]) return (double)income * (double)brackets[0][1]/100;
        double total_tax=0;
        for(int i=0;i<brackets.size();i++) {
            if(i==0 || income>=(brackets[i][0]-brackets[i-1][0])) {
                income-=(i==0)?brackets[i][0]:brackets[i][0]-brackets[i-1][0];
                if(i==0) total_tax+= (double)brackets[0][0]*(double)brackets[0][1]/100;
                else total_tax+=(double)(brackets[i][0]-brackets[i-1][0])*(double)brackets[i][1]/100;
            } else {
                total_tax+=(double)income*(double)brackets[i][1]/100;
                break;
            }
        }
        
        return total_tax;
    }
};