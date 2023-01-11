#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve1() {
    int a,b,c,m;
    cin>>a>>b>>c>>m;
    int max=0;
    if(a>1) {
        max+=a-1;
    }
    if(b>1) {
        max+=b-1;
    }
    if(c>1) {
        max+=c-1;
    }
    int v[3];
    v[0]=a;
    v[1]=b;
    v[2]=c;
    sort(v,v+3);
    int d=v[2]-v[1]-v[0]-1;
    if(d<0) {
        d=0;
    }
    int min=d;
    if(m>=min && m<=max) {
        cout<<"YES"<<endl;
    }
    else {
        cout<<"NO"<<endl;
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
        solve1();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}