#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    float t,n;
    cin>>t>>n;
    if(n==0) {
        float run_rate=t/20;
        if(run_rate<=10) {
            cout<<"MI"<<endl;
        }
        else {
            cout<<"CSK"<<endl;
        }
    }
    else {
        float runs=0;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            runs+=k;
        }
        float run_rate=(t-runs)/(20-n);
        if(run_rate<=10) {
            cout<<"MI"<<endl;
        }
        else {
            cout<<"CSK"<<endl;
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