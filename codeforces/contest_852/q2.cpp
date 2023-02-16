#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int x,y;
    cin>>x>>y;
    int n=2*abs(x-y);
    cout<<n<<endl;
    vector<int> v;
    while(y!=x) {
        v.push_back(y);
        y++;
    }
    v.push_back(y);
    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<" ";
    }
    v.pop_back();
    reverse(v.begin(),v.end());
    v.pop_back();
    for(int i=0;i<v.size();i++) {
        cout<<v[i]<<" ";
    }
    cout<<endl;
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