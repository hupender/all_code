#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int sum=0;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        sum+=k;
        v.push_back(k);
    }
    if(sum%2==0) {
        cout<<"0"<<endl;
    }
    else {
        int r=INT_MAX;
        for(int i=0;i<n;i++) {
            int count=0;
            if(v[i]%2==0) {
                while(v[i]%2==0) {
                    count++;
                    v[i]/=2;
                }
            }
            else {
                while(v[i]%2!=0) {
                    count++;
                    v[i]/=2;
                }
            }
            r=min(r,count);
        }
        cout<<r<<endl;
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