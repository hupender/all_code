#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    ll score[n];
    // score[n-1]=a[n-1];
    for(int i=n-1;i>=0;i--) {
        if(i+a[i]<n) {
            score[i]=a[i]+score[i+a[i]];
        }
        else {
            score[i]=a[i];
        }
    }
    ll lar=INT_MIN;
    for(int i=0;i<n;i++) {
        lar=max(lar,score[i]);
    }
    cout<<lar<<endl;
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