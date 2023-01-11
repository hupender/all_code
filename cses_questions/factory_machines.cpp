#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,k;
    cin>>n>>k;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int p;
        cin>>p;
        v.push_back(p);
    }
    ll low=1,high=1e18;
    ll time=0;
    while(low<high) {
        if(abs(low-high)==1) {
            break;
        }
        ll mid=(low+high)/2;
        ll total_product=0;
        for(int i=0;i<n;i++) {
            total_product+=mid/v[i];
            if(total_product>k) {
                break;
            }
        }
        if(total_product<k) {
            low=mid;
        }
        else if(total_product>k) {
            high=mid;
        }
        else {
            time=mid;
            high=mid;
            // break;
        }
    }
    ll ans;
    if(time>0) {
        ans=time;
        cout<<ans<<endl;
        // for(ll t=time-1;t>0;t--) {
        //     ll total_product=0;
        //     for(int i=0;i<n;i++) {
        //         total_product+=t/v[i];
        //     }
        //     if(total_product!=k) {
        //         break;
        //     }
        //     else {
        //         ans=t;
        //     }
        // }
        // cout<<ans<<endl;
    }
    else {
        ll total_product=0;
        for(int i=0;i<n;i++) {
            total_product+=low/v[i];
        }
        if(total_product>=k) {
            cout<<low<<endl;
            // time=low;
        }
        else {
            time=high;
            cout<<high<<endl;
        }
        // ans=time;
    }
    // for(ll t=time-1;t>0;t--) {
    //     ll total_product=0;
    //     for(int i=0;i<n;i++) {
    //         total_product+=t/v[i];
    //     }
    //     if(total_product!=k) {
    //         break;
    //     }
    //     else {
    //         ans=t;
    //     }
    // }
    // cout<<ans<<endl;
}
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    // int t;
    // cin>>t;
    // while(t--) {
    solve();
    // }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}