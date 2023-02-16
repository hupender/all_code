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
    int greater_than=INT_MIN,less_than=INT_MAX;
    int flag1=0,flag2=0;
    for(int i=0;i<n-1;i++) {
        if(a[i]<a[i+1]) {
            int val=(a[i]+a[i+1])/2;
            less_than=min(val,less_than);
            flag1=1;
        }
        else if(a[i]>a[i+1]) {
            int val=(a[i]+a[i+1]+1)/2;
            greater_than=max(val,greater_than);
            flag2=1;
        }
    }
    if(flag1 && flag2) {
        if(less_than>=greater_than) {
            cout<<less_than<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
    }
    else if(flag1) {
        cout<<less_than<<endl;
    }
    else if(flag2) {
        cout<<greater_than<<endl;
    }
    else {
        cout<<"0"<<endl;
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