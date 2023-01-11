#include<bits/stdc++.h>
using namespace std;
int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        v.push_back(k);
    }
    
    unordered_map<int,int> m;
    for(int i=0;i<n;i++) {
        m[v[i]]++;
    }
    v.clear();
    for(auto i:m) {
        v.push_back(i.first);
    }
    sort(v.begin(),v.end());
    for(auto i:m) {
        while(i.second>1) {
            v.push_back(i.first);
            i.second--;
        }
    }
    
    int k=1,i=0;
    while(i<n) {
        if(v[i]==k) {
            i++;
            k++;
        }
        else if(i<=n-2) {
            n-=2;
            k++;
        }
        else {
            break;
        }
    }
    cout<<k-1<<endl;
}