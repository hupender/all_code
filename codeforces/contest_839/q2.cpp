#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int a,b,c,d;
    cin>>a>>b>>c>>d;
    int mi=min(a,min(b,min(c,d)));
    int ma=max(a,max(b,max(c,d)));
    if(a==ma && d==mi) {
        cout<<"Yes"<<endl;
    }
    else if(b==ma && c==mi) {
        cout<<"Yes"<<endl;
    }
    else if(c==ma && b==mi) {
        cout<<"Yes"<<endl;
    }
    else if(d==ma && a==mi) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
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