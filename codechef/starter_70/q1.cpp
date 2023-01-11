#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0;i<n;i++) {
        if(s[i]=='1') {
            v.push_back(i);
        }
    }
    int odd_count=0,even_count=0;
    for(int i=0;i<v.size();i++) {
        if(v[i]%2==0) {
            even_count++;
        }
        else {
            odd_count++;
        }
    }
    if(odd_count==0 || even_count==0) {
        cout<<"2"<<endl;
    }
    else {
        cout<<"1"<<endl;
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