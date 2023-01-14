// { Driver Code Starts
//Initial Template for C++


#include<bits/stdc++.h>
using namespace std;


 // } Driver Code Ends
//User function Template for C++

class Solution{
    public:
  
    long long calculateSum(int n, int m, int k, vector<vector<int>> matrix)
    {
        // code here
        vector<vector<long long>> v1;
        for(int i=0;i<n;i++) {
            vector<long long> v;
            map<long long,int> s;
            for(int j=0;j<k;j++) {
                s[matrix[i][j]]++;
            }
            map<long long,int>::iterator it;
            it=s.begin();
            v.push_back(it->first);
            int l=0;
            for(int j=k;j<m;j++) {
                if(s[matrix[i][l]]>1) {
                    s[matrix[i][l]]--;
                }
                else {
                    it=s.find(matrix[i][l]);
                    s.erase(it);
                }
                s[matrix[i][j]]++;
                it=s.begin();
                v.push_back(it->first);
                l++;
            }
            v1.push_back(v);
        }
        
        vector<vector<long long>> v2;
        for(int j=0;j<v1[0].size();j++) {
            vector<long long> v;
            map<long long,int> s;
            for(int i=0;i<k;i++) {
                s[v1[i][j]]++;
            }
            map<long long,int>::iterator it;
            it=s.begin();
            v.push_back(it->first);
            int l=0;
            for(int i=k;i<v1.size();i++) {
                if(s[v1[l][j]]>1) { 
                    s[v1[l][j]]--;
                }
                else {
                    it=s.find(v1[l][j]);
                    s.erase(it);
                }
                s[v1[i][j]]++;
                it=s.begin();
                v.push_back(it->first);
                l++;
            }
            v2.push_back(v);
        }




        // for(int j=0;j<m-k+1;j++) {
        //     vector<long long> v;
        //     map<long long,int> s;
        //     for(int i=0;i<k;i++) {
        //         s[v1[i][j]]++;
        //     }
        //     map<long long,int>::iterator it;
        //     it=s.begin();
        //     v.push_back(it->first);
        //     int l=0;
        //     for(int i=k;i<n;i++) {
        //         if(s[v1[i][l]]>1) {
        //             s[v1[i][j]]--;
        //         }
        //         else {
        //             map<long long,int>::iterator it1=s.find(v1[l][j]);
        //             s.erase(it1);
        //         }
        //         s[v1[i][j]]++;
        //         it=s.begin();
        //         v.push_back(it->first);
        //         l++;
        //     }
        //     v2.push_back(v);
        // }
        long long res=0;
        for(int i=0;i<v2.size();i++) {
            for(int j=0;j<v2[i].size();j++) {
                res+=v2[i][j];
            }
        }
        return res;
    }

};

// { Driver Code Starts.

signed main()
{
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int T;
    cin>>T;
    while(T--)
    {
        int N,M,K;
        cin>>N>>M>>K;
        vector<vector<int>> matrix(N,vector<int>(M));
        for(int i=0;i<N;i++){
            for(int j=0;j<M;j++){
                cin>>matrix[i][j];
            }
        } 
        Solution ob;
        auto ans = ob.calculateSum(N, M, K, matrix);
        cout<<ans<<endl;
    }
    return 0;
}  // } Driver Code Ends