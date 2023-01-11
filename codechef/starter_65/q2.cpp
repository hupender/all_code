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
        // vector<int> v;
        unordered_map<int,int> m;
        for(int i=0;i<2*n;i++) {
            int k;
            cin>>k;
            m[k]++;
            // v.push_back(k);
        }
        int flag=1;
        for(auto i:m) {
            if(i.second>2) {
                flag=0;
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