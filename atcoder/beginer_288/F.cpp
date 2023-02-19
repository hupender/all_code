#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int mod=998244353;
void solve1() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0;i<n;i++) {
        v.push_back(s[i]-'0');
    }
    ll res[n];
    res[0]=v[0];
    ll ans=1+res[0];
    for(int i=1;i<n;i++) {
        ll res1=10*res[i-1]+v[i]*ans;
        res1%=mod;
        res[i]=res1;
        ans+=res[i];
        ans%=mod;
    }
    cout<<res[n-1]<<endl;
}
void solve() {
    int n;
    cin>>n;
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0;i<n;i++) {
        v.push_back(s[i]-'0');
    }
    ll res[n];
    // memset(res,0,sizeof(res));
    res[n-1]=v[n-1];
    for(int i=n-2;i>=0;i--) {
        ll ans=0;
        ll num1=0;
        int j;
        for(j=i;j<n-1;j++) {
            num1*=10;
            num1+=v[j];
            num1%=mod;
            ans+=num1*(res[j+1]);
            ans%=mod;
        }
        num1*=10;
        num1+=v[j];
        num1%=mod;
        ans+=num1;
        ans%=mod;
        res[i]=ans;
    }
    cout<<res[0]<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    solve1();
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}