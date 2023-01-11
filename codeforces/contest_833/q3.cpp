#include<bits/stdc++.h>
using namespace std;
typedef long long int ll;
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
        vector<ll> sum;
        ll sum1=0;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
            sum1+=k;
            sum.push_back(sum1);
        }
        int count=0;
        for(int i=0;i<n;i++) {
            if(sum[i]==0) {
                count++;
            }
        }
        for(int i=0;i<n;i++) {
            if(v[i]==0) {
                if(sum[i]!=0) {
                    
                }
            }
        }
    }
}