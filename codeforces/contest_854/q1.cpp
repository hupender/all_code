#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve1() {
    int n,m;
    cin>>n>>m;
    vector<int> v;
    unordered_map<int,int> map;
    for(int i=0;i<n;i++) {
        v.push_back(i+1);
        map[v[i]]++;
    }
    vector<int> res(n,-1);
    int ind=n-1;
    for(int i=0;i<m;i++) {
        int p;
        cin>>p;
        if(map[p]==0 && ind>=0) {
            res[ind]=i+1;
            ind--;
        }
        map[p]++;
    }
    for(int i=0;i<n;i++) {
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
        solve1();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}