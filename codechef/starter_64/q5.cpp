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
        for(int i=0;i<2*n;i++) {
            int k;
            cin>>k;
            m[k]++;
            v.push_back(k);
        }
        int lar=0;
        int sum=0;
        for(auto i:m) {
            sum+=i.second;
            lar=max(lar,i.second);
        }
        sum-=lar;
        int p=lar-sum;
        if(n==1) {
            cout<<"yes"<<endl;
        }
        else if(p>0 && p/2>(n+1)/2) {
            cout<<"no"<<endl;
        }
        else {
            cout<<"yes"<<endl;
        }
    }
}