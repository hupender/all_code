#include<bits/stdc++.h>
using namespace std;
// int find_smallest(vector<int> v) {
//     int ans=INT_MAX,ind;
//     for(int i=0;i<v.size();i++) {
//         if(v[i]<ans) {
//             ind=i;
//             ans=v[i];
//         }
//     }
//     return ind;
// }

int main() {
    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        string s;
        cin>>s;
        vector<int> v(n);
        long long sum=0;
        for(int i=0;i<n;i++) {
            if(s[i]=='L') {
                v[i]=i;
            }
            else {
                v[i]=n-1-i;
            }
            sum+=v[i];
        }
        sort(v.begin(),v.end());
        int flag=0;
        int k=1;
        while(k<=n) {
            if(flag==0) {
                // int ind=find_smallest(v);
                int ind=k-1;
                if(v[ind]<=n-1-v[ind]) {
                    sum=sum+n-1-2*v[ind];
                    v[ind]=n-1-v[ind];
                    cout<<sum<<" ";
                }
                else {
                    flag=1;
                    cout<<sum<<" ";
                }
            }
            else {
                cout<<sum<<" ";
            }
            k++;
        }
        cout<<endl;
    }
}