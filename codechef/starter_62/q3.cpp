#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,q;
        cin>>n>>q;
        vector<int> v;
        int sum=0;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            sum+=k;
            v.push_back(k);
        }
        for(int i=0;i<q;i++) {
            int l,r;
            cin>>l>>r;
            int p=r-l+1;
            if(p%2!=0) {
                sum++;
            }
        }
        cout<<sum<<endl;
    }
}