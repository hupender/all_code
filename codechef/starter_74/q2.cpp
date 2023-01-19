#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int get_gcd(int a,int b) {
    if(b==0) {
        return a;
    }
    return get_gcd(b,a%b);
}
void solve() {
    int a,b;
    cin>>a>>b;
    int g=get_gcd(a,b);
    cout<<a-g<<endl;
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