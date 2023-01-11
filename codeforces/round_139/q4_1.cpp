#include<bits/stdc++.h>
using namespace std;
vector<vector<int>> get_one_factor() {
    int mod=10000000;
    vector<bool> visited(mod+1,false);
    vector<vector<int>> v(mod+1);
    for(int i=2;i<=mod;i++) {
        if(!visited[i]) {
            int n=i;
            int j=2;
            while(n<=mod) {
                v[n].push_back(i);
                visited[n]=true;
                n=i*j;
                j++;
            }
        }
    }
    return v;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    vector<vector<int>> v=get_one_factor();
    int n=v.size();
    for(int i=2;i<n;i++) {
        int k=v[i].size();
        cout<<i<<" : ";
        for(int j=0;j<k;j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    
}