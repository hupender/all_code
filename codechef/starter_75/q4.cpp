#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int l,r;
    cin>>l>>r;
    int n=r;
    int count=0;
    while(n) {
        n/=2;
        count++;
    }
    int num=1;
    for(int i=0;i<count;i++) {
        num*=2;
    }
    if(num>r) {
        count--;
        num/=2;
    }
    int res=(2*num)-1+(count);
    cout<<res<<endl;
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