#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
        }
        if(v[0]==v[n-1] || v[0]==v[n-2] || v[1]==v[n-1]) {
            cout<<"yes"<<endl;
        }
        else {
            int flag=0;
            for(int i=1;i<n-1;i++) {
                if(v[0]==v[i] && v[i+1]==v[n-1]) {
                    flag=1;
                    break;
                }
            }
            if(flag) {
                cout<<"yes"<<endl;
            }
            else {
                cout<<"no"<<endl;
            }
        }
    }
}