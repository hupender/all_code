#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int a[n],b[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    for(int i=0;i<n;i++) {
        cin>>b[i];
    }
    sort(a,a+n);
    sort(b,b+n,greater<int>());
    int c[n];
    for(int i=0;i<n;i++) {
        c[i]=a[i]+b[i];
    }
    int flag=1,val=c[0];
    for(int i=1;i<n;i++) {
        if(c[i]!=val) {
            flag=0;
            break;
        }
    }
    if(flag) {
        for(int i=0;i<n;i++) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++) {
            cout<<b[i]<<" ";
        }
        cout<<endl;
    } else {
        cout<<"-1"<<endl;
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