#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
vector<int> decimal_to_bianry(int n) {
    vector<int> v(32,0);
    int ind=31;
    while(n) {
        int p=n%2;
        v[ind]=p;
        ind--;
        n/=2;
    }
    return v;
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        vector<int> v1=decimal_to_bianry(k);
        v.push_back(v1);
    }
    vector<int> v2;
    for(int j=0;j<32;j++) {
        int count=0;
        for(int i=0;i<n;i++) {
            if(v[i][j]==1) {
                count++;
            }
        }
        v2.push_back(count);
    }
    int ma=0,mi=0;
    int m=1;
    for(int i=31;i>=0;i--) {
        if(v2[i]>0) {
            ma+=m;
        }
        if(v2[i]==n) {
            mi+=m;
        }
        m*=2;
    }
    cout<<ma-mi<<endl;

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