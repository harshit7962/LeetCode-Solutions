class Solution {
public:
    string intToRoman(int num) {
        string res="";
        for(int i=0;i<num/1000;i++) res+='M';
        num=num%1000;
        for(int i=0;i<num/900;i++) res+="CM";
        num=num%900;
        for(int i=0;i<num/500;i++) res+='D';
        num=num%500;
        for(int i=0;i<num/400;i++) res+="CD";
        num=num%400;
        for(int i=0;i<num/100;i++) res+='C';
        num=num%100;
        for(int i=0;i<num/90;i++) res+="XC";
        num=num%90;
        for(int i=0;i<num/50;i++) res+='L';
        num=num%50;
        for(int i=0;i<num/40;i++) res+="XL";
        num=num%40;
        for(int i=0;i<num/10;i++) res+='X';
        num=num%10;
        for(int i=0;i<num/9;i++) res+="IX";
        num=num%9;
        for(int i=0;i<num/5;i++) res+='V';
        num=num%5;
        for(int i=0;i<num/4;i++) res+="IV";
        num=num%4;
        for(int i=0;i<num;i++) res+='I';
        
        return res;
    }
};