#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    ll k,x;
    cin>>n>>k>>x;
    ll a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    sort(a,a+n);
    int count=0;
    vector<ll> v;
    for(int i=0;i<n-1;i++) {
        if(a[i+1]-a[i]>x) {
            v.push_back(a[i+1]-a[i]);
            count++;
        }
    }
    sort(v.begin(),v.end());
    int n1=count;
    for(int i=0;i<n1;i++) {
        ll q=v[i]/x;
        ll r=v[i]%x;
        if(r==0) {
            q--;
        }
        if(k>=q) {
            count--;
            k-=q;
        }
        else {
            break;
        }
    }
    // if(count==0) {
    //     cout<<"1"<<endl;
    // }
    cout<<count+1<<endl;
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
    solve();
    // }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}