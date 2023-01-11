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
        int ma=0;
        long long res=0;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            res+=k;
        }
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            ma=max(k,ma);
            res+=k;
        }
        cout<<res-ma<<endl;
    }
}