#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        // vector<int> v;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            m[k]++;
        }
        // if(n%2==0) {
        //     cout<<"YES"<<endl;
        // }
        // else {
        //     cout<<"NO"<<endl;
        // }

        int x=m.size();
        if(x%2==0) {
            cout<<"YES"<<endl;
        }
        else {
            int flag=0;
            for(auto i:m) {
                if(i.second>1) {
                    flag=1;
                    break;
                }
            }
            if(flag==1) {
                cout<<"YES"<<endl;
            }
            else {
                cout<<"NO"<<endl;
            }
        }
    }
}