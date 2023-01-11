#include<bits/stdc++.h>
using namespace std;
#define ll long long int
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        int min_ind;
        int mi=INT_MAX;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            if(k<mi) {
                mi=k;
                min_ind=i;
            }
        }
        if(min_ind!=0) {
            cout<<"Alice"<<endl;
        }
        else {
            cout<<"Bob"<<endl;
        }
    }
}