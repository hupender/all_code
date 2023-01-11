#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int n,m,k;
    cin>>n>>m>>k;
    vector<int> v;
    set<pair<int,int>> s;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        v.push_back(k);
    }
    vector<int> v1;
    ll sum=0;
    
    for(int i=0;i<m;i++) {
        s.insert({v[i],i});
    }

    set<pair<int,int>> ::iterator k_th;
    int j=1;
    pair<int,int> p;
    for(auto i:s) {
        if(j==k) {
            p=i;
        }
        j++;
    }
    k_th=s.find(p);

    set<pair<int,int>> ::iterator it=s.begin();
    j=k;
    while(j--) {
        sum+=it->first;
        it++;
    }
    j=0;
    v1.push_back(sum);
    for(int i=m;i<n;i++) {
        set<pair<int,int>> ::iterator it1=s.find({v[j],j});
        int d=distance(k_th,it1);
        if(d<=0) {
            k_th++;
            sum=sum-v[j]+k_th->first;
            k_th--;
        }
        s.erase(it);
        s.insert({v[i],i});
        set<pair<int,int>> ::iterator it2=s.find({v[i],i});
        int d1=distance(k_th,it2);
        if(d1<=0) {
            k_th++;
            sum+=v[i]-k_th->first;
            k_th--;
        }
        v1.push_back(sum);
        j++;
    }
    for(int i=0;i<v1.size();i++) {
        cout<<v1[i]<<" ";
    }
    cout<<endl;
}