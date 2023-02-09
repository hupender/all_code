#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int a[n];
    // map<int,int> map1;
    for(int i=0;i<n;i++) {
        cin>>a[i];
        // map1[a[i]]++;
    }
    sort(a,a+n);
    ll count=0;
    int val=1;
    for(int i=0;i<n;i++) {
        if(a[i]>val) {
            count+=a[i]-val;
            val++;
        }
        else {
            while(a[i]==val) {
                i++;
            }
            i--;
            val++;
        }
    }
    cout<<count<<endl;
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