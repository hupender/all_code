#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,k;
    cin>>n>>k;
    ll prod=1;
    for(int i=0;i<n;i++) {
        int l;
        cin>>l;
        prod*=l;
    }
    if(2023%prod==0) {
        cout<<"Yes"<<endl;
        cout<<2023/prod;
        for(int i=0;i<k-1;i++) {
            cout<<" 1";
        }
        cout<<endl;
    } else {
        cout<<"NO"<<endl;
    }
}
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        solve();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}