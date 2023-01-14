// { Driver Code Starts
//Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution {
    public:
    long long minTime(int n, int x, int src, int dest, int m1, int m2,vector<vector<int>> airlines, vector<vector<int>> railways){
        // code here
    }
};

// { Driver Code Starts.

int main(){
    int T;
    cin >> T;
    while(T--){
        int N, X, src, dest;
        cin >> N >> X;
        cin >> src >> dest;
        int M1, M2;
        cin >> M1;
        vector<vector<int>> airlines(M1, vector<int> (3));
        for(int i = 0; i < M1; i++){
            cin >> airlines[i][0] >> airlines[i][1] >> airlines[i][2];
        }
        cin >> M2;
        vector<vector<int>> railways(M2, vector<int> (3));
        for(int i = 0; i < M2; i++){
            cin >> railways[i][0] >> railways[i][1] >> railways[i][2];
        }
        Solution obj;
        cout << obj.minTime(N, X, src, dest, M1, M2, airlines, railways) << "\n";
    }
}
  // } Driver Code Ends