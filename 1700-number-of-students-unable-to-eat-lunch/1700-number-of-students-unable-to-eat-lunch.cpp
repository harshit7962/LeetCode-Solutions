class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        queue<int> q;
        for(int i=0;i<students.size();i++) q.push(students[i]);
        
        int curr=0, i=0, count=0;
        while(i<sandwiches.size() && (count<=sandwiches.size()-curr)) {
            if(q.front()==sandwiches[i]) {
                q.pop();
                curr++;
                i++;
                count=0;
            }
            
            count++;
            q.push(q.front());
            q.pop();
        }
        
        return students.size()-curr;
    }
};