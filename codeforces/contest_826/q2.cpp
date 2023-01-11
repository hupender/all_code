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
        if(n==3) {
            cout<<"-1"<<endl;
        }
        else {
            vector<int> v;
            for(int i=0;i<n;i++) {
                v.push_back(i+1);
            }
            if(n%2==0) {
                for(int i=0;i<n;i=i+2) {
                    swap(v[i],v[i+1]);
                }
            }
            else {
                int p=1;
                for(int i=n/2;i<n;i++) {
                    v[i]=p;
                    p++;
                }
                for(int i=0;i<n/2;i++) {
                    v[i]=p;
                    p++;
                }
                // reverse(v.begin(),v.end());
                // swap(v[n/2],v[(n+1)/2]);
            }
            for(int i=0;i<n;i++) {
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }
    }
}