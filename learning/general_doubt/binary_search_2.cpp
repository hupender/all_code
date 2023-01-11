#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,p;
    cin>>n>>p;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        v.push_back(k);
    }
    int low=1,high=n;
    while(low<high) {
        int mid=(low+high)/2;
        if(v[mid-1]<p) {
            low=mid+1;
        }
        else if(v[mid-1]>p) {
            high=mid-1;
        }
        else {
            high=mid;
            break;
        }
    }
    cout<<high+1<<endl;
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