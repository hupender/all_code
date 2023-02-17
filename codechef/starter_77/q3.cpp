#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,k;
    cin>>n>>k;
    ll a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    if(k==n) {
        int flag=1;
        for(int i=0;i<n/2;i++) {
            if(a[i]!=a[n-1-i]) {
                flag=0; 
            }
        }
        if(flag) {
            cout<<"YES"<<endl;
        }
        else {
            cout<<"NO"<<endl;
        }
    }
    else {
        if(n%2==0 && k%2==0) {
            // check palindrome
            int x=(k-2)/2;
            ll add=0;
            int ind;
            for(int i=0;i<x;i++) {
                add+=abs(add+a[i]-a[n-1-i]);
                a[k-1-i]+=add;
                ind=k-1-i;
            }
            if(x!=0) {
                for(int i=x;i<ind;i++) {
                    a[i]+=add;
                }
            }
            ll sum=0;
            for(int i=x;i<n/2;i++) {
                sum+=abs(a[i]-a[n-1-i]);
            }
            if(sum%2==0) {
                cout<<"YES"<<endl;
            }
            else {
                cout<<"NO"<<endl;
            }
        }
        else {
            cout<<"YES"<<endl;
        }
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