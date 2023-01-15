#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef hupi
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int n;
    cin>>n;
    vector<pair<pair<int,int>,int>> v;
    for(int i=0;i<n;i++) {
        int a,b,c;
        cin>>a>>b>>c;
        v.push_back({{a,b},c});
    }
    sort(v.begin(),v.end());
    for(int i=0;i<n;i++) {
        cout<<v[i].first.first<<" "<<v[i].first.second<<" "<<v[i].second;
        cout<<endl;
    }
    cout<<endl;
}