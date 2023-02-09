#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve1() {
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int flag=1;
    for(int i=1;i<n;i++) {
        if(a[i]!=a[0]) {
            flag=0;
        }
    }
    if(flag && n%2==0) {
        cout<<"Zenyk"<<endl;
    }
    else {
        cout<<"Marichka"<<endl;
    }

}
void solve() {
    int n;
    cin>>n;
    int a[n];
    map<int,int> m;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        m[a[i]]++;
    }
    int flag=0;
    for(auto i:m) {
        if(i.second%2!=0) {
            flag=1;
        }
    }
    if(flag) {
        cout<<"Marichka"<<endl;
    }
    else {
        cout<<"Zenyk"<<endl;
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