#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        long long int sum=0;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            sum+=k;
        }
        cout<<abs(sum)<<endl;
    }
}