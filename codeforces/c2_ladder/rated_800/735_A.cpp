#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
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
        vector<int> v;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
        }
        ll max_prod=0;
        for(int i=0;i<n-1;i++) {
            ll prod=1;
            prod*=v[i];
            prod*=v[i+1];
            max_prod=max(max_prod,prod);
        }
        cout<<max_prod<<endl;
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<"endl";
    #endif
}