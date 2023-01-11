#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
ll gcd(int a,int b) {
    if(b==0) {
        return a;
    }
    return gcd(b,a%b);
}
void solve() {
    int n;
    cin>>n;
    ll a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    if(n==1) {
        cout<<"1"<<endl;
    }
    // else if(n==2) {
    //     if(a[0]==a[1]) {
    //         cout<<"0"<<endl;
    //     }
    //     else {
    //         cout<<max(a[0],a[1])<<endl;
    //     }
    // }
    // else if(n==3) {
    //     ll g=gcd(a[0],a[2]);
    //     if(a[1]%g!=0) {
    //         cout<<g<<endl;
    //     }
    //     else if(a[0]%a[1]!=0 && a[2]%a[1]!=0) {
    //         cout<<a[1]<<endl;
    //     }
    //     else {
    //         cout<<"0"<<endl;
    //     }
    // }
    else {
        ll g1=a[0],g2=a[1];
        for(int i=2;i<n;i++) {
            if(i%2==0) {
                g1=gcd(g1,a[i]);
            }
            else {
                g2=gcd(g2,a[i]);
            }
        }
        int flag=1;
        for(int i=0;i<n;i++) {
            if(i%2==0) {
                if(a[i]%g2==0) {
                    flag=0;
                    break;
                }
            }
        }
        if(flag) {
            cout<<g2<<endl;
        }
        else {
            flag=1;
            for(int i=0;i<n;i++) {
                if(i%2!=0) {
                    if(a[i]%g1==0) {
                        flag=0;
                        break;
                    }
                }
            }
            if(flag) {
                cout<<g1<<endl;
            }
            else {
                cout<<"0"<<endl;
            }
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