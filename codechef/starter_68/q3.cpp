#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,x,c;
        cin>>n>>x>>c;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
        }
        int count=0;
        int sum=0;
        for(int i=0;i<n;i++) {
            if(v[i]+c<x) {
                count++;
            }
            else {
                sum+=v[i];
            }
        }
        sum+=count*(x-c);
        cout<<sum<<endl;
    }
}