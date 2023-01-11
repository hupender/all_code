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
        // vector<int> lid;
        // for(int i=0;i<n;i++) {
        //     int k;
        //     cin>>k;
        //     lid.push_back(k);
        // }
        string lid;
        cin>>lid;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
        }
        for(int i=1;i<n;i++) {
            if(v[i-1]>=v[i] && lid[i-1]=='0' && lid[i]=='1') {
                lid[i-1]='1';
                lid[i]='0';
            }
            else if(v[i-1]<v[i] && lid[i-1]=='0' && lid[i]=='1') {
                int ind=i-1;
                int p=v[i-1];
                while(lid[i]=='1') {
                    if(v[i]<=p) {
                        lid[ind]='1';
                        lid[i]='0';
                        break;
                    }
                    i++;
                }
            }
        }
        int sum=0;
        for(int i=0;i<n;i++) {
            if(lid[i]=='1') {
                sum+=v[i];
            }
        }
        cout<<sum<<endl;
    }
}