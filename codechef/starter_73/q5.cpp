#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int

// void solve1() {
//     int n,m,k;
//     cin>>n>>m>>k;
//     vector<pair<int,int>> v;
//     for(int i=0;i<k;i++) {
//         int a,b;
//         cin>>a>>b;
//         v.push_back({a,b});
//     }
//     // sort(v.begin(),v.end());
//     vector<pair<int,int>> v1;
//     vector<pair<int,int>> v2;
//     for(int i=0;i<k;i++) {
//         if(v[i].first<n && v[i].second<m) {
//             v1.push_back({v[i].first,v[i].second});
//             v2.push_back({v[i].second,v[i].first});
//         }
//     }
//     sort(v1.begin(),v1.end());
//     sort(v2.begin(),v2.end());
//     vector<pair<int,int>> v3;
//     for(int i=0;i<k;i++) {
//         v3.push_back({v2[i].second,v2[i].first});
//     }
//     ll res=(ll)(n-1)*(m-1);
//     if(v1.size()==0 || k==0) {
//         cout<<res<<endl;
//     }
//     else {
//         // find longest common subsequence in v1 and v3
//     }
// }
void solve() {
    int n,m,k;
    cin>>n>>m>>k;
    vector<pair<int,int>> v;
    for(int i=0;i<k;i++) {
        int a,b;
        cin>>a>>b;
        v.push_back({a,b});
    }
    // sort(v.begin(),v.end());
    vector<pair<int,int>> v1;
    vector<pair<int,int>> v2;
    for(int i=0;i<k;i++) {
        if(v[i].first<n && v[i].second<m) {
            v1.push_back({v[i].first,v[i].second});
            v2.push_back({v[i].second,v[i].first});
        }
    }
    sort(v1.begin(),v1.end());
    sort(v2.begin(),v2.end());
    vector<pair<int,int>> v3;
    map<pair<int,int>,int> map, visited1;
    for(int i=0;i<k;i++) {
        v3.push_back({v2[i].second,v2[i].first});
        map[{v2[i].second,v2[i].first}]=i;
    }
    int max_count=INT_MIN;
    // we will be working on vector 1 and 3
    // unrordered_map<pair<int,int>,bool> visited;
    vector<bool> visited(k,false);
    for(int i=0;i<k;i++) {
        int count=0;
        int ind=map[{v1[i].first,v1[i].second}];
        visited[ind]=true;
        for(int j=ind+1;j<k;j++) {
            if(!visited[j]) {
                count++;
            }
        }
        max_count=max(max_count,count);
    }
    ll res=(ll)(n-1)*(m-1);
    if(k==0) {
        cout<<res<<endl;
    }
    else {
        cout<<res-max_count<<endl;
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