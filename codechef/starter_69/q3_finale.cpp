#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
vector<int> decimal_to_binary(int n) {
    vector<int> v(30,0);
    int i=29;
    while(n>0) {
        v[i]=n%2;
        n/=2;
        i--;
    }
    return v;
}

void solve1(vector<vector<int>> &v,unordered_map<int,int> &m) {
    int n=v.size();
}
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        vector<int> p=decimal_to_binary(k);
    }
    unordered_map<int,int> m;
    for(int i=0;i<n;i++) {
        for(int j=0;j<30;j++) {
            if(v[i][j]==1) {
                m[j]++;
            }
        }
    }
    solve1(v,m);
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