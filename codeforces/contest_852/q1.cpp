#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int a,b;
    cin>>a>>b;
    int n,m;
    cin>>n>>m;
    ll res1=0,res2=0;
    if(m>=n) {
        res1=a*(ll)n;
        res2=b*(ll)n;
        cout<<min(res1,res2)<<endl;
    }
    else {
        // find cost of m+1 potato on both day;
        res1=m*(ll)a;
        res2=(m+1)*(ll)b;
        if(res1>res2) {
            ll res=n*(ll)b;
            cout<<res<<endl;
        }
        else {
            int count=n/(m+1);
            int rem=n-count*(m+1);
            ll res=count*m*(ll)a;
            if(a<=b) {
                res+=rem*(ll)a;
            }
            else {
                res+=rem*(ll)b;
            }
            cout<<res<<endl;
        }
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