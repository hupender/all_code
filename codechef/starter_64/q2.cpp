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
        int lar=0;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            lar=max(lar,k);
        }
        cout<<lar<<endl;
    }
}