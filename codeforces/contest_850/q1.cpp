#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int p=2;
    int bob=0,alice=1;
    n--;
    int flag=1;
    while(n>0) {
        if(flag) {
            int b=p+p+1;
            if(n>b) {
                bob+=b;
                n-=b;
            }
            else {
                bob+=n;
                n=0;
            }
            p+=2;
            flag=0;
        }
        else {
            int a=2*p+1;
            if(n>a) {
                alice+=a;
                n-=a;
            }
            else {
                alice+=n;
                n=0;
            }
            p+=2;
            flag=1;
        }
    }
    cout<<alice<<" "<<bob<<endl;
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