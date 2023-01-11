#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    ll t;
    cin>>t;
    while(t--) {
        ll n,m;
        cin>>n>>m;
        ll res;
        ll count_2=0,count_5=0;
        ll p=n;
        while(p%2==0) {
            count_2++;
            p=p/2;
        }
        while(p%5==0) {
            count_5++;
            p=p/5;
        }
        ll c=abs(count_2-count_5);
        ll x=1;
        ll flag=1,count_flag=0;
        if(count_5>count_2) {
            flag=2;
            while(c--&& x<=m) {
                x*=2;
                count_flag++;
            }
        }
        else if(count_2>count_5) {
            flag=5;
            while(c-- && x<=m) {
                x*=5;
                count_flag++;
            }
        }
        ll count=0;
        while(x<m) {
            x*=10;
            count++;
        }
        ll flag2=0;
        ll y=x;
        if(x>m) {
            if(count_flag && count) {
                x=x/flag;
                if(x<m) {
                    ll q1=m/x;
                    x=q1*x;
                    flag2=1;
                }
                y=y/10;
                ll q2=m/y;
                y=q2*y;
                if(flag2) {
                    x=max(y,x);
                }
                else {
                    x=y;
                }
            }
            else if(count) {
                x=x/10;
                ll q2=m/x;
                x=q2*x;
            }
            else if(count_flag) {
                x=x/flag;
                ll q1=m/x;
                x=q1*x;
            }
            else {
                x=m;
            }
        }
        // if(x>m) {
        //     if(x/flag<m) {
        //         flag2=1;
        //         x=x/flag;
        //         ll q=m/x;
        //         x=q*x;
        //     }
        //     if(count>0) {
        //         y=y/10;
        //         ll q1=m/y;
        //         y=q1*y;
        //     }  
        // }
        // if(flag2 && count) {
        //     x=max(y,x);
        // }
        // else {
        //     if(!flag2 && count) {
        //         x=y;
        //     }
        // }
        res=n*x;
        cout<<res<<endl;
    }
}