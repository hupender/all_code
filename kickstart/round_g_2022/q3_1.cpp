#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve(int t) {
    int n;
    cin>>n;
    int pre[n];
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
        if(i==0) {
            pre[i]=a[i];
        }
        else {
            pre[i]=pre[i-1]+a[i];
        }
    }
    ll sum=0;
    vector<int> v;
    for(int i=0;i<n;i++) {
        if(a[i]>=0) {
            v.push_back(i);
            sum+=a[i];
        }
    }
    int size=v.size();
    for(int i=0;i<size;i++) {
        int ind=v[i];
        int l=1;
        while(ind+l<n) {
            ll r;
            if(ind==0) {
                r=pre[ind+l];
            }
            else {
                r=pre[ind+l]-pre[ind-1];
            }
            if(r>=0) {
                sum+=r;
            }
            else {
                break;
            }
            l++;
        }
    }
    cout<<"Case #"<<t<<": "<<sum<<endl;
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
    for(int i=1;i<=t;i++) {
        solve(i);
    }
    // solve();
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}