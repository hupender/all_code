#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int mod=998244353;
void solve() {
    int l,r;
    cin>>l>>r;
    int st=l;
    int count=0;
    while(st<=r) {
        count++;
        st*=2;
    }
    int end=r;
    int step=count-1;
    while(step--) {
        end/=2;
    }
    int max_limit=end;
    ll res=max_limit-l+1;
    int val=r;
    int step1=count-2;
    while(step1--) {
        val/=2;
    }
    // get sum of harmonic progression
    // float t1=(2*max_limit+1);
    // float t2=(2*l-1);
    // float sum=log(t1/t2);
    // float sum=log(2*(max_limit)+1)-log(2*(l-1)+1);
    // sum*=val;
    // sum-=2*(max_limit-l+1);
    // sum*=(count-1);
    // ll res1=0;
    // res1=sum;
    // float sum=(2*max_limit+1)/(float)(2*l-1);
    
    ll res1=0;
    for(int i=l;i<=max_limit;i++) {
        int num=val/i;
        num-=2;
        res1+=num;
        res1%=mod;
    }
    res1*=(count-1);
    res1%=mod;
    res+=res1;
    res%=mod;
    cout<<count<<" "<<res<<endl;
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