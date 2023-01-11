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
        vector<int> d;
        vector<int> a;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            d.push_back(k);
        }
        a.push_back(d[0]);
        int sum=d[0];
        int flag=1;
        for(int i=1;i<n;i++) {
            sum+=d[i];
            if(a[i-1]>=d[i] && a[i-1]!=0 && d[i]!=0) {
                flag=0;
                break;
            }
            else {
                a.push_back(sum);
            }
        }
        if(!flag) {
            cout<<"-1"<<endl;
        }
        else {
            for(int i=0;i<n;i++) {
                cout<<a[i]<<" ";
            }
            cout<<endl;
        }
    }
}