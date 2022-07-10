class Solution {
public:
    bool canChange(string start, string target) {  
        
        int countL=0, countR=0;
        
        for(int i=0;i<start.size();i++) {
            if(start[i]=='L') countL++;
            else if(start[i]=='R') countR++;
            
            if(countL!=0 && countR!=0) return false;
            
            if(target[i]=='L') countL--;
            else if(target[i]=='R') countR--;
            
            if(countL!=0 && countR!=0) return false;
            
            if(countL>0) return false;
            if(countR<0) return false;
            // cout << countL << " " << countR << endl;
        }
        
        return (countL==0 && countR==0);
//         int i = 0;
        
//         while(i<start.size()) {
//             if(start[i] == target[i]) {i++; continue;}
            
//             if(start[i]=='_' && target[i] == 'L') {
//                 int j=i;
//                 while(j<start.size() && start[j]!='L') {
//                     j++;
//                     if(start[j]=='R') return false;
//                 }
                
//                 if(j==start.size()) return false;
                
//                 swap(start[i], start[j]);
//             }  else if(start[i]=='R' && target[i]=='_') {
//                 int j=i;
//                 while(j<start.size() && start[j]!='_') {
//                     j++;
//                     if(start[j]=='L') return false;
//                 }
                
//                 if(j==start.size()) return false;
                
//                 swap(start[i], start[j]);
//             } else return false;
            
//             i++;
//         }
        
//         return true;
    }
};