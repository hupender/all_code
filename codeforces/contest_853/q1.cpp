#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int gcd(int a,int b) {
    if(b==0) {
        return a;
    }
    return gcd(b,a%b);
}
void solve() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int min_gcd=INT_MAX;
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            int g=gcd(a[i],a[j]);
            min_gcd=min(min_gcd,g);
        }
    }
    if(min_gcd<=2) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
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