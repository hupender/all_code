#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
ll gcd(int w,int d) {
    if(d==0) {
        return w;
    }
    return gcd(d,w%d);
}

pair<int,int> get_result(int a,int b) {
    ll g=gcd(a,b);
    int q1=a/b;
    int rem=a%b;
    a=b;
    b=rem;
    int x=1;
    if(rem==g) {
        return {x,-q1};
    }
    if(rem==0) {
        return {0,g};
    }
    while(a%b!=g) {
        int rem2=a%b;
        int q2=a/b;
        x=-(q2*x);
        q1=(1-q1*q2);
        a=b;
        b=rem2;
    }
    pair<int,int> res={x,-q1};
    return res;
}
void solve() {
    ll n,p,w,d;
    cin>>n>>p>>w>>d;
    ll g=gcd(w,d);
    if(p%g==0) {
        pair<int,int> p1=get_result(w,d);
        ll fact=p/g;
        ll x,y,z;
        x=p1.first*fact;
        y=p1.second*fact;
        z=n-x-y;
        if(x>=0 && y>=0 && z>=0) {
            cout<<x<<" "<<y<<" "<<z<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
        
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
    solve();
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}