#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    ll n,x;
    cin>>n,x;
    if(n==x) {
        cout<<n<<endl;
    }
    else {
        int flag=1;
        ll y=x;
        while(x>1) {
            if(x%2!=0) {
                flag=0;
                break;
            }
            x/=2;
        }
        if(flag) {
            int count1=0,count2=0;
            while(y>0) {
                y/=2;
                count1++;
            }
            while(n>0) {
                n/=2;
                count2++;
            }
            if(count1==count2) {
                //
            }
            else if(count1==0) {
                //
            }
            else {
                cout<<"-1"<<endl;
            }
        }
        else {
            cout<<"-1"<<endl;
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