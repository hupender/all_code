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
    sort(a,a+n,greater<int>());
    int b=a[0],ind;
    int count=0;
    for(int i=0;i<n;i++) {
        if(a[i]==b) {
            count++;
        }
        else {
            ind=i;
            break;
        }
    }
    if(count==n) {
        cout<<"NO"<<endl;
    }
    else {
        cout<<"YES"<<endl;
        cout<<a[0]<<" ";
        for(int i=ind;i<n;i++) {
            cout<<a[i]<<" ";
        }
        for(int i=1;i<ind;i++) {
            cout<<a[i]<<" ";
        }
        cout<<endl;
        // for(int i=0;i<n/2;i++) {
        //     cout<<a[i]<<" "<<a[n-i-1]<<" ";
        // }
        // if(n%2==0) {
        //     cout<<a[n/2];
        // }
        // cout<<endl;
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