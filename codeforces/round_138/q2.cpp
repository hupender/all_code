#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a;
        vector<int> b;
        for(int i=0;i<n;i++) {
            long long int k;
            cin>>k;
            a.push_back(k);
        }
        map<int,vector<int>> m;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            b.push_back(k);
        }
        for(int i=0;i<n;i++) {
            m[b[i]].push_back(i);
        }
        long long int ans=0;
        vector<bool> visited(n,false);
        for(auto i:m) {
            for(auto j:i.second) {
                ans+=a[j];
                visited[j]=true;
                int ind=j;
                while(visited[ind] ) {
                    ind++;
                }
                if(ind<n) {
                    a[ind]+=i.first;
                }
                ind=j;

                while(visited[ind] ) {
                    ind--;
                }
                if(ind>=0) {
                    a[ind]+=i.first;
                }
            }
        }
        cout<<ans<<endl;
    }
    
}