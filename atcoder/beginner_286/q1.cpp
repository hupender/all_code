#include<bits/stdc++.h>
using namespace std;
int main() {
    int n,p,q,r,s;
    cin>>n>>p>>q>>r>>s;
    int a[n];
    for(int i=0;i<n;i++) {
        cin>>a[i];
    }
    vector<int> v;
    int ind=r-1;
    for(int i=p-1;i<q;i++) {
        v.push_back(a[i]);
        a[i]=a[ind];
        ind++;
    }
    int k=0;
    for(int i=r-1;i<s;i++) {
        a[i]=v[k];
        k++;
    }
    for(int i=0;i<n;i++) {
        cout<<a[i]<<" ";
    }
    cout<<endl;
}