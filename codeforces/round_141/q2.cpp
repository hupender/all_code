#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    int st=1,end=n*n;
    vector<vector<int>> v(n,vector<int>(n));
    int j=0;
    vector<int> v1;
    while(st<=end) {
        v1.push_back(st);
        v1.push_back(end);
        st++;
        end--;
    }
    int k=0;
    for(int i=0;i<n;i++) {
        vector<int> v2;
        for(int j=0;j<n;j++) {
            v2.push_back(v1[k]);
            k++;
        }
        if(i%2!=0) {
            reverse(v2.begin(),v2.end());
        }
        for(int j=0;j<n;j++) {
            v[i][j]=v2[j];
        }
    }
    for(int i=0;i<n;i++) {
        for(int j=0;j<n;j++) {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
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