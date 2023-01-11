#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int x,y;
    cin>>x>>y;
    if((x==1 && y==1) || (x==2 && y==2)) {
        cout<<x<<endl;
    }
    else if(x==1) {
        cout<<y-1<<endl;
    }
    else if(y==1) {
        cout<<x-1<<endl;
    }
    else {
        ll res=(ll)x*y;
        res=res-x-y;
        cout<<res<<endl;
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