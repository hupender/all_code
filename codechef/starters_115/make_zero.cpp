#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int a[n];
    map<int,vector<int> > m;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        m[a[i]].push_back(i);
    }
    int till_subtract=0,num_op=0,end=n;
    for(auto i:m) {
        int size=i.second.size();
        int ind=i.second[0];
        if(v[ind])
    }
    cout<<num_op<<endl;
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