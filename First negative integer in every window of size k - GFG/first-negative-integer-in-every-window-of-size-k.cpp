// { Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

vector<long long> printFirstNegativeInteger(long long int arr[],
                                             long long int n, long long int k);

// Driver program to test above functions
int main() {
    long long int t, i;
    cin >> t;
    while (t--) {
        long long int n;
        cin >> n;
        long long int arr[n];
        for (i = 0; i < n; i++) {
            cin >> arr[i];
        }
        long long int k;
        cin >> k;

        vector<long long> ans = printFirstNegativeInteger(arr, n, k);
        for (auto it : ans) cout << it << " ";
        cout << endl;
    }
    return 0;
}
// } Driver Code Ends


vector<long long> printFirstNegativeInteger(long long int A[], long long int N, long long int K) {
    long long int start=0, end=0;
    queue<long long int> q;
    vector<long long int> res;
    
    while(end<K) {
        if(A[end]<0) q.push(end);
        end++;
    }
    end--;
    while(end<N) {
        if(A[end]<0) q.push(end);
        while(!q.empty() && start>q.front()) q.pop();
        
        if(q.empty()) res.push_back(0);
        else res.push_back(A[q.front()]);
        start++;
        end++;
    }
    
    return res;
}