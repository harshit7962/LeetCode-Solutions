class Solution {
public:
    int countStudents(vector<int>& students, vector<int>& sandwiches) {
        int count=0, curr1=0, curr2=0;
        while(curr1<students.size() && curr2<sandwiches.size() && count<sandwiches.size()-curr2) {
            if(students[curr1]==sandwiches[curr2]) {
                curr1++;
                curr2++;
                count=0;
            } else {
                students.push_back(students[curr1]);
                curr1++;
                count++;
            }
        }
        
        return sandwiches.size()-curr2;
    }
};