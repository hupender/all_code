#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
ll power(int x,int y,int m) {
    ll res=1;
    while(y--) {
        res*=x;
        res%=m;
    }
    return res;
}
void solve() {
    int n,m;
    cin>>n>>m;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        v.push_back(k);
    }
    sort(v.begin(),v.end());
    ll score=0;
    for(int i=0;i<n-1;i++) {
        ll r1=power(v[n-1],v[i],m);
        ll r2=power(v[i],v[n-1],m);
        score+=(r1+r2)%m;
    }
    cout<<score<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--) {
    //     solve();
    // }
    solve();
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}