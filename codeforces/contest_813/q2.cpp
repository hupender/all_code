#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++) {
            v.push_back(i+1);
        }
        for(int i=n-1;i>0;i=i-2) {
            swap(v[i],v[i-1]);
        }
        for(int i=0;i<n;i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}