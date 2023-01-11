#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    string s;
    cin>>s;
    int n=s.size();
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        v[i]=s[i]-'0';
    }
    int flag=1;
    for(int i=n-1;i>0;i--) {
        if(v[i]+v[i-1]>9) {
            int sum=v[i]+v[i-1];
            v[i-1]=sum/10;
            v[i]=sum%10;
            flag=0;
            break;
        }
    }
    if(flag) {
        cout<<v[0]+v[1];
        for(int i=2;i<n;i++) {
            cout<<v[i];
        }
    }
    else {
        for(int i=0;i<n;i++) {
            cout<<v[i];
        }
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