#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,k;
    cin>>n>>k;
    int a[n];
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
            int flag=1;
            ll total_increment=0;
            for(int i=0;i<n/2;i++) {
                if(a[i]!=a[n-1-i]) {
                    total_increment+=(abs(a[i]-a[n-1-i])); 
                    total_increment%=k;  
                    flag=0;
                }
            }
            if(flag || total_increment==0) {
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