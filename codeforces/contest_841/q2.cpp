#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int mod=1e9+7;
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
        int n;
        cin>>n;
        int num=n/2;
        ll res=1;
        ll first=num;
        ll second=2*num+1;
        ll third=2*num-1;
        if(first%3==0) {
            first/=3;
        }
        else if(second%3==0) {
            second/=3;
        }
        else {
            third/=3;
        }
        res*=first;
        res%=mod;
        res*=second;
        res%=mod;
        res*=third;
        res%=mod;
        res*=2;
        res%=mod;
        if(n%2!=0) {
            ll other=n*(n-1);
            other%=mod;
            res+=other;
            res%=mod;
        }
        res*=2022;
        res%=mod;

        ll res1=1;
        first=n;
        second=2*n+1;
        third=n+1;
        if(first%3==0) {
            first/=3;
        }
        else if(second%3==0) {
            second/=3;
        }
        else {
            third/=3;
        }
        res1*=first;
        res1%=mod;
        res1*=second;
        res1%=mod;
        res1*=third;
        res1%=mod;
        res1*=1011;
        res1%=mod;
        res+=res1;
        res%=mod;
        cout<<res<<endl;
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}