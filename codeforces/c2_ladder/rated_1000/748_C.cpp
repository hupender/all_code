#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int x,n;
    cin>>x>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    int time=x-1;
    int count=0;
    for(int i=n-1;time>0 && i>=0;i--) {
        time-=(x-a[i]);
        if(time>=0) {
            count++;
        }
    }
    cout<<count<<endl;
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