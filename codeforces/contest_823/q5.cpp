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
        int count=0;
        for(int i=0;i<n;i++) {
            count++;
            int mi=v[i];
            int ma=v[i];
            for(int j=i+1;j<n;j++) {
                if(v[j]<=mi) {
                    mi=v[j];
                }
                if(v[j]>=ma) {
                    ma=v[j];
                }
                if(ma%mi==0) {
                    count++;
                }

            }
        }
        cout<<count<<endl;
    }
}