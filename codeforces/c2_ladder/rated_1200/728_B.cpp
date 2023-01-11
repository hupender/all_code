#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve1() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    pair<ll,ll> b[n];
    for(int i=0;i<n;i++) {
        b[i]={a[i],i+1};
    }
    sort(b,b+n);
    ll count=0;
    for(int i=0;i<n-1;i++) {
        int flag=0;
        for(int j=i+1;j<n;j++) {
            if(b[i].first*b[j].first==b[i].second+b[j].second) {
                count++;
                flag=1;
            }
            else if(b[i].first*b[j].first>2*n-1) {
                break;
            }
        }
        // if(!flag) {
        //     break;
        // }
    }
    cout<<count<<endl;
}
void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    pair<ll,ll> b[n];
    for(int i=0;i<n;i++) {
        b[i]={a[i],i+1};
    }
    sort(b,b+n);
    ll count=0;
    for(int i=0;i<n-1;i++) {
        int flag=0;
        for(int j=i+1;j<n;j++) {
            if(b[i].first*b[j].first==b[i].second+b[j].second) {
                count++;
                flag=1;
            }
            else if(b[i].first*b[j].first>b[i].second+b[j].second) {
                break;
            }
        }
        if(!flag) {
            break;
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
        solve1();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}