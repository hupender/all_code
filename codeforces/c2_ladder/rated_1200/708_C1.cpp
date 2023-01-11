#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,k;

    cin>>n>>k;

    int a,b,c;
    if(n%2==0) {
        if(n%4==0) {
            a=n/4;
            b=n/4;
            c=n/2;
        }
        else {
            a=2;
            b=(n-2)/2;
            c=(n-2)/2;
        }
    }
    else {
        a=1;
        b=n/2;
        c=n/2;
    }
    cout<<a<<" "<<b<<" "<<c<<endl;
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