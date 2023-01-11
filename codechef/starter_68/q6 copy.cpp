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
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
            m[k]++;
        }
        int flag=1;
        for(auto i:m) {
            if(i.second>=(n+3)/2) {
                flag=0;
                break;
            }
        }
        sort(v.begin(),v.end());
        if(flag) {
            vector<int> v1;
            int low=0,high=n-1;
            while(low<high) {
                v1.push_back(v[low]);
                v1.push_back(v[high]);
                low++;
                high--;
            }
            if(low==high) {
                v1.push_back(v[low]);
            }
            for(int i=0;i<n;i++) {
                cout<<v1[i]<<" ";
            }
            cout<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
    }
}