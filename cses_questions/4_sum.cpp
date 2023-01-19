#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,x;
    cin>>n>>x;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<pair<int,int>> v1;
    for(int i=0;i<n;i++) {
        v1.push_back({a[i],i});
    }
    sort(v1.begin(),v1.end());
    sort(a,a+n);
    vector<pair<int,pair<int,int>>> v;
    for(int i=0;i<n-1;i++) {
        for(int j=i+1;j<n;j++) {
            v.push_back({a[i]+a[j],{i,j}});
        }
    }
    sort(v.begin(),v.end());
    int low=0,high=v.size()-1;
    int flag=0;
    int ind1,ind2,ind3,ind4;
    while(low<high) {
        long long sum=(long long)v[low].first+v[high].first;
        if(sum==x) {
            ind1=v[low].second.first;
            ind2=v[low].second.second;
            ind3=v[high].second.first;
            ind4=v[high].second.second;
            unordered_map<int,int> m;
            m[ind1]++;
            m[ind2]++;
            m[ind3]++;
            m[ind4]++;
            int flag1=1;
            for(auto i:m) {
                if(i.second>1) {
                    flag1=0;
                }
            }
            if(flag1) {
                flag=1;
                break;
            }
            else {
                low++;
            }
        }
        else if(sum<x) {
            low++;
        }
        else {
            high--;
        }
    }
    if(flag) {
        cout<<v1[ind1].second+1<<" "<<v1[ind2].second+1<<" "<<v1[ind3].second+1<<" "<<v1[ind4].second+1<<endl;
    }
    else {
        cout<<"IMPOSSIBLE"<<endl;
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
    solve();
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}