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
        int m1=(n+1)/2-1;
        int m2=(n+2)/2-1;
        int count=0;
        int flag=1;
        while(m1>=0 && m2<n) {
            v[m1]+=count;
            if(v[m1]>v[m2]) {
                flag=0;
                break;
            }
            else {
                count+=v[m2]-v[m1];
            }
            m1--;
            m2++;
        }
        if(flag) {
            cout<<count<<endl;
        }
        else {
            cout<<"-1"<<endl;
        }
    }
}