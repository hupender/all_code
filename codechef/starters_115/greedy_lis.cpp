#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,x;
    cin>>n>>x;
    if(x==0) {
        for(int i=0;i<n;i++) {
            cout<<i+1<<" ";
        }
        cout<<endl;
    } else {
        if(n<x+2) {
            cout<<"-1"<<endl;
        }
        else {
            vector<int> v;
            v.push_back(n);
            int m=n-x-1;
            int k=n;
            n=n-m;
            while(m--) {
                cout<<k<<" ";
                k--;
            }
            int i=1;
            while(n--) {
                cout<<i<<" ";
                i++;
            }
            cout<<endl;
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