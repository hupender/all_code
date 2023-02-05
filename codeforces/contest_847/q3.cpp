#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    vector<vector<int>> v;
    for(int i=0;i<n;i++) {
        vector<int> v1;
        for(int j=0;j<n-1;j++) {
            int k;
            cin>>k;
            v1.push_back(k);
        }
        v.push_back(v1);
    }
    vector<int> res=v[0];
    unordered_map<int,int> m;
    for(int i=0;i<n-1;i++) {
        m[res[i]]++;
    }
    int remain_ele;
    for(int i=1;i<=n;i++) {
        if(m[i]==0) {
            remain_ele=i;
            break;
        }
    }
    unordered_map<int,int> prev;
    for(int i=1;i<n;i++) {
        int j=0;
        while(j<n-1 && v[i][j]!=remain_ele) {
            prev[v[i][j]]++;
            j++;
        }
    }
    int ind=0;
    for(int i=0;i<n-1;i++) {
        if(prev[res[i]]>0) {
            ind++;
        }
        else {
            break;
        }
    }
    for(int i=0;i<ind;i++) {
        cout<<res[i]<<" ";
    }
    cout<<remain_ele<<" ";
    for(int i=ind;i<n-1;i++) {
        cout<<res[i]<<" ";
    }
    cout<<endl;
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