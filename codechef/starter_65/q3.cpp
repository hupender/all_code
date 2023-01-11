#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> v;
        int count=0;
        for(int i=0;i<n;i++) {
            int p;
            cin>>p;
            v.push_back(p);
            if(p==k) {
                count++;
            }
        }
        if(n==1 && count==1) {
            cout<<"yes"<<endl;
        }
        else if(count==0 || count==1 && v[n-1]==k) {
            cout<<"no"<<endl;
        }
        else {
            cout<<"yes"<<endl;
        }
    }
}