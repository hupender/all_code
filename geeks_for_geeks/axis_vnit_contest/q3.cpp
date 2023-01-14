// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
    bool wifiRange(int n, string s, int x){
        // code here
        vector<int> v;
        for(int i=0;i<n;i++) {
            if(s[i]=='1') {
                v.push_back(i);
            }
        }
        int size=v.size();
        if(size==0 || v[0]>x || v[size-1]<n-x-1) {
            return false;
        }
        else {
            if(size==1) {
                if(v[0]>x || v[size-1]<n-x-1) {
                    return false;
                }
                else {
                    return true;
                }
            }
            else {
                for(int i=0;i<size-1;i++) {
                    if(v[i+1]-v[i]>2*x) {
                        return false;
                    }
                }
            }
        }
        return true;
    }
};

// { Driver Code Starts.

int main(){
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int T;
    cin >> T;
    while(T--){
        int N, X;
        string S;
        cin >> N >> X >> S;
        Solution obj;
        cout << obj.wifiRange(N, S, X) << "\n";
    }
}
  // } Driver Code Ends