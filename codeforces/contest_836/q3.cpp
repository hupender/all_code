#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,x;
        cin>>n>>x;
        vector<int> v;
        v.push_back(x);
        if(n%x==0) {
            // cout<<x<<" ";
            for(int i=2;i<n;i++) {
                if(i==x) {
                    v.push_back(n);
                }
                else {
                    // cout<<i<<" ";
                    v.push_back(i);
                }
            }
            // cout<<"1"<<endl;
            v.push_back(1);
            for(int i=0;i<n;i++) {
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
    }
}