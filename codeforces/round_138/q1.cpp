#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        // vector<vector<int>> v(n,vector<int> (n,0));
        unordered_map<int,int> row;
        unordered_map<int,int> col;
        for(int i=0;i<m;i++) {
            int a,b;
            cin>>a>>b;
            row[a-1]++;
            col[b-1]++;
            // v[a-1][b-1]=1;
        }
        int flag=0;
        for(int i=0;i<n;i++) {
            if(row[i]==0 || col[i]==0) {
                flag=1;
                break;
            }
        }
        if(flag) {
            cout<<"yes"<<endl;
        }
        else {
            cout<<"no"<<endl;
        }
    }

}