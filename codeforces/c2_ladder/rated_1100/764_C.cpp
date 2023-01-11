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
    for(int i=0;i<n;i++) {
        if(a[i]>n) {
            while(a[i]>n) {
                a[i]/=2;
            }
        }
    }
    unordered_map<int,int> m;
    for(int i=0;i<n;i++) {
        m[a[i]]++;
    }
    for(int i=0;i<n;i++) {
        if(m[a[i]]>1) {
            m[a[i]]--;
            while(a[i]>1 && m[a[i]]>0) {
                a[i]/=2;
            }
            m[a[i]]++;
        }
    }
    
    if(m.size()==n) {
        cout<<"Yes"<<endl;
    }
    else {
        cout<<"No"<<endl;
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