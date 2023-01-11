#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,a,b;
    cin>>n>>a>>b;
    string s;
    cin>>s;
    vector<int> v;
    for(int i=0;i<n;i++) {
        v.push_back(s[i]-'0');
    }
    if(b>=0) {
        cout<<n*(a+b)<<endl;
    }
    else {
        int count_zero=0,count_one=0;
        int ind=0;
        if(v[0]==0) {
            count_zero++;
        }
        else {
            count_one++;
        }
        for(int i=1;i<n;i++) {
            if(v[i-1]<v[i]) {
                count_one++;
            }
            if(v[i]<v[i-1]) {
                count_zero++;
            }
        }
        int m=min(count_zero,count_one);
        int res=(m+1)*b+n*a;
        cout<<res<<endl;
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