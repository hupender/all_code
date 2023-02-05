#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    string res;
    for(int i=0;i<n-1;i++) {
        if(s[i]=='n' && s[i+1]=='a') {
            res.push_back(s[i]);
            res.push_back('y');
            res.push_back(s[i+1]);
            i++;
        }
        else {
            res.push_back(s[i]);
        }
    }
    if(n==1) {
        res.push_back(s[0]);
    }
    else {
        if(s[n-1]!='a' || s[n-2]!='n') {
            res.push_back(s[n-1]);
        }
    }
    cout<<res<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--) {
    solve();
    // }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}