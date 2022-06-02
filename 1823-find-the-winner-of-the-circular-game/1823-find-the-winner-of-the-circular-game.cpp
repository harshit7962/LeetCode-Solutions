class Solution {
public:
    int findTheWinner(int n, int k) {
        queue<int> q;
        for(int i=1;i<=n;i++) q.push(i);
        int x=1;
        while(q.size()!=1) {
            if(x!=k) {
                q.push(q.front());
                q.pop();
                x++;
            } else {
                q.pop();
                x=1;
            }
        }
        return q.front();
    }
};