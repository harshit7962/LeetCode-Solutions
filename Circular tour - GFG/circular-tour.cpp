// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

struct petrolPump
{
    int petrol;
    int distance;
};


 // } Driver Code Ends
/*
The structure of petrolPump is 
struct petrolPump
{
    int petrol;
    int distance;
};*/

/*You are required to complete this method*/
class Solution{
  public:
  
    //Function to find starting point where the truck can start to get through
    //the complete circle without exhausting its petrol in between.
    int tour(petrolPump p[],int n)
    {
        int total_petrol = 0, total_dist = 0;
        
        int size = n;
        
        for(int i=0;i<size;i++) {
            total_petrol += p[i].petrol;
            total_dist += p[i].distance;
        }
        
        if(total_dist > total_petrol) return -1;
        
        int start = 0, curr = 0, petrol = 0;
        
        
        while(curr<size) {
            petrol+=p[curr].petrol;
            int nxt = p[curr].distance;
            
            if(nxt>petrol) {
                start = curr+1;
                petrol = 0;
            } else {
                petrol -= nxt;
            }
            
            curr++;
        }
        
        return start;
    }
};



// { Driver Code Starts.

int main()
{
    int t;
    cin>>t;
    while(t--)
    {
        int n;
        cin>>n;
        petrolPump p[n];
        for(int i=0;i<n;i++)
            cin>>p[i].petrol>>p[i].distance;
        Solution obj;
        cout<<obj.tour(p,n)<<endl;
    }
}
  // } Driver Code Ends