// { Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
bool isValid(int a[],int n, int m,int mid){
        int sum=0;
        int student=1;
        for(int i=0;i<n;i++){
            sum = sum+a[i];
            if(sum>mid){
                student++;
                sum = a[i];
            }
            if(student>m){
                return false;
            }
        }
        return true;
}
    //Function to find minimum number of pages.
    int findPages(int a[], int n, int m) 
    {
        //code here
        int max=INT_MIN;
        for(int i=0;i<n;i++){
            if(a[i]>max){
                max=a[i];
            }
        }
        int start=max;
        int sum=0;
        for(int i=0;i<n;i++){
            sum += a[i];
        }
        int end=sum;
        int ans=-1;
        int mid;
        while(start<=end){
            mid= start + (end-start)/2;
            if(isValid(a,n,m,mid)){
                ans=mid;
                end=mid-1;
            }
            else{
                start=mid+1;
            }
        }
        
        return ans;
    }
};

// { Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}
  // } Driver Code Ends