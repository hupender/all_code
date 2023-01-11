#include<bits/stdc++.h>
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    freopen("input.txt","r",stdin);
    freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a;
        vector<int> b;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            a.push_back(k);
        }
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            b.push_back(k);
        }
        vector<int> dmin;
        vector<int> dmax;
        for(int i=0;i<n;i++) {
            int flag=0;
            for(int j=0;j<n;j++) {
                if(b[j]>=a[i]) {
                    dmin.push_back(b[j]-a[i]);
                }
            }
            for(int j=i+1;j<n;j++) {
                if(a[j]>b[j-1]) {
                    dmax.push_back(b[j-1]-a[i]);
                    flag=1;
                    break;
                }
            }
            if(flag==0) {
                dmax.push_back(b[n-1]-a[i]);
            }
        }
        dmax.push_back(b[n-1]-a[n-1]);
        for(int i=0;i<n;i++) {
            cout<<dmin[i]<<" ";
        }
        cout<<endl;
        for(int i=0;i<n;i++) {
            cout<<dmax[i]<<" ";
        }
        cout<<endl;
    }
}