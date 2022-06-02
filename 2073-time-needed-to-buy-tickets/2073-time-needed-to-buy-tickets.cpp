class Solution {
public:
    int timeRequiredToBuy(vector<int>& tickets, int k) {
        int res=0;
        
        for(int i=0;i<=k;i++) {
            if(tickets[i]<=tickets[k]) res+=tickets[i];
            else res+=tickets[k];
        }
        for(int i=k+1;i<tickets.size();i++) {
            if(tickets[i]<tickets[k]) res+=tickets[i];
            else res+=tickets[k]-1;
        }
        
        return res;
    }
};