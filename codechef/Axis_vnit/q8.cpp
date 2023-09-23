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
    int res1=0,res2=0;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            res1+=a[i]^a[j];
        }
    }
    res1*=2;
    vector<int> v;
    for(int i=0;i<n;i++) {
        for(int j=i+1;j<n;j++) {
            v.push_back(a[i]|a[j]);
        }
    }
    int size=v.size();
    for(int i=0;i<size;i++) {
        for(int j=0;j<n;j++) {
            res2+=v[i]^a[j];
        }
    }
    res2*=2;
    cout<<res1+res2<<endl;
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