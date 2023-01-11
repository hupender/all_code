#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
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
        int p=2*v[0]-1;
        int count=0;
        for(int i=1;i<n;i++) {
            if(v[i]>p) {
                int q=v[i]/p;
                int r=v[i]%p;
                if(r==0) {
                    count+=q-1;
                }
                else {
                    count+=q;
                }
            }
        }
        cout<<count<<endl;
    }
}