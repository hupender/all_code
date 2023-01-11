#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
    //fast input output
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>> n;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
        }
        // sort(v.begin(),v.end());
        int m,k;
        vector<int> ans;
        for(int i=0;i<n;i++) {
            m=-1;
            k=-1;
            for(int j=0;j<n;j++) {
                if(v[j]<2*v[i] && j!=i) {
                    m=max(m,v[j]);
                }
                else if(v[j]<=v[i] && j!=i) {
                    k=max(k,v[j]);
                }
            }
            if(m==-1) {
                ans.push_back(k);
            }
            else {
                ans.push_back(m);
            }
        }
        for(int i=0;i<n;i++) {
            cout<<ans[i]<<" ";
        }
        cout<<endl;
    }
}