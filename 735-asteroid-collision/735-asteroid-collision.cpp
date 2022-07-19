class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        stack<int> st;
        st.push(asteroids[0]);
        
        for(int i=1;i<asteroids.size();i++) {
            int curr = asteroids[i];
            if(curr>0) st.push(curr);
            else {
                while(!st.empty() && st.top()>0 && curr<0)  {
                    if(st.top() < abs(curr)) st.pop();
                    else break;
                }
            
                if(!st.empty() && st.top()==abs(curr)) st.pop();
                else if(st.empty() || st.top()<0) {st.push(curr);}
            }
        }
        
        vector<int> res(st.size());
        
        int ind = st.size()-1;
        while(!st.empty()) {res[ind--] = st.top(); st.pop();}
        
        return res;
    }
};