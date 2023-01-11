#include<bits/stdc++.h>
using namespace std;
int main() {
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int x=1;x<=t;x++) {
        int m,n,p;
        cin>>m>>n>>p;
        vector<vector<int>> v;
        for(int i=0;i<m;i++) {
            vector<int> v1;
            for(int i=0;i<n;i++) {
                int k;
                cin>>k;
                v1.push_back(k);
            }
            v.push_back(v1);
        }
        int ans=0;
        for(int i=0;i<n;i++) {
            int m1=0;
            for(int j=0;j<m;j++) {
                m1=max(v[j][i],m1);
            }
            ans+=m1-v[p-1][i];
        }
        cout<<"Case #"<<x<<": "<<ans<<endl;
    }
}