#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
vector<int> get_binary(int n) {
    vector<int> v(32,0);
    int k=31;
    while(n>0) {
        int r=n%2;
        v[k]=r;
        k--;
        n/=2;
    }

    return v;
}
void solve() {
    int n,y;
    cin>>n>>y;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    int or_1=a[0];
    for(int i=1;i<n;i++) {
        or_1|=a[i];
    }
    vector<int> v1=get_binary(or_1);
    vector<int> v2=get_binary(y);
    int flag=1;
    vector<int> v3(32,0);
    for(int i=0;i<32;i++) {
        if(v1[i]==1 && v2[i]==0) {
            flag=0;
            break;
        }
        else if(v1[i]==0 && v2[i]==1) {
            v3[i]=1;
        }
    }

    if(flag) {
        int res=0,m=1;
        for(int i=31;i>=0;i--) {
            res+=v3[i]*m;
            m*=2;
        }
        cout<<res<<endl;
    }
    else {
        cout<<"-1"<<endl;
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