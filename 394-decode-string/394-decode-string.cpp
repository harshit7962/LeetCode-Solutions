class Solution {
public:
    string decodeString(string s) {
        stack<int> numbers;
        stack<string> result;
        string res="";
        
        int index=0;
        while(index<s.size()) {
            if(s[index]>='0' && s[index]<='9') {
                int num = 0;
                while(s[index]>='0' && s[index]<='9') {
                    num = num*10+(s[index]-'0');
                    index++;
                }
                numbers.push(num);
            } else if(s[index]=='[') {
                result.push(res);
                res="";
                index++;
            } else if(s[index]==']') {
                string temp = result.top();
                result.pop();
                int num = numbers.top();
                numbers.pop();
                
                while(num>0) {
                    num--;
                    temp+=res;
                }
                res = temp;
                index++;               
            } else {
                res+=s[index];
                index++;
            }
        }
        
        return res;
    }
};