#include<bits/stdc++.h>
using namespace std;

int get_min_swap(vector<int> v,int k) {
    int count=0;
    for(int i=k;i<v.size();i++) {
        if(v[i]<=k) {
            count++;
        }
    }
    return count;
}

int main() {
    int t;
    cin>> t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int p;
            cin>>p;
            v.push_back(p);
        }
        int ans=get_min_swap(v,k);
        cout<<ans<<endl;
    }
}