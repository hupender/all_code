#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,s,r;
    cin>>n>>s>>r;
    int one=s-r;
    int avg=(r)/(n-1);
    int rem=r%(n-1);
    int rem1=n-1-rem;
    while(rem1) {
        cout<<avg<<" ";
        rem1--;
    }
    while(rem) {
        cout<<avg+1<<" ";
        rem--;
    }
    cout<<one<<endl;
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