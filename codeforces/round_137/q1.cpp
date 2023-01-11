#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
        }
        int m=10-n;
        int ans=6;
        if(m==2) {
            cout<<ans<<endl;
        }
        else {
            ans*=m*(m-1)/2;
            cout<<ans<<endl;
        }
    }
}