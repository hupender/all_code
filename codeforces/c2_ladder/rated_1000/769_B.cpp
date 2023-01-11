#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int m=n-1;
    int val=1;
    while(m) {
        m/=2;
        val*=2;
    }
    val/=2;
    int res=1;
    for(int i=1;i<val;i++) {
        cout<<i<<" ";
    }
    cout<<"0 ";
    for(int i=val;i<n;i++) {
        cout<<i<<" ";
    }
    cout<<endl;
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