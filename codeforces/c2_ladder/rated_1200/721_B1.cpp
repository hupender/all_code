#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    int count_zero=0;
    for(int i=0;i<n;i++) {
        if(s[i]=='0') {
            count_zero++;
        }
    }
    if(count_zero==0) {
        cout<<"DRAW"<<endl;
    }
    if(count_zero%2==0 || count_zero==1) {
        cout<<"BOB"<<endl;
    }
    else {
        cout<<"ALICE"<<endl;
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