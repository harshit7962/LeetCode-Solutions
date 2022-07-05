class Solution {
public:
    long long waysToBuyPensPencils(int total, int cost1, int cost2) {
        long long res=0;
        
        long long num_pencils=0;
        
        while(total-cost2*num_pencils>=0) {
            long long num_pens = (total-cost2*num_pencils)/cost1;
            res+=num_pens+1;
            num_pencils++;
        }
        
        return res;
    }
};