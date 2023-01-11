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
        int flag=1;
        for(int i=0;i<n;i=i+2) {
            if(abs(v[i+1]-v[i])!=1) {
                flag=0;
            }
        }
        if(n==1) {
            flag=1;
        }
        if(!flag) {
            cout<<"-1"<<endl;
        }
        else {
            int count=0;
            int d=1;
            while(n>=2 && flag) {
                int k=0;
                for(int i=0;i<n;i=i+2) {
                    if(v[i+1]<v[i]) {
                        count++;
                        if(abs(v[i]-v[i+1])>d) {
                            flag=0;
                        }
                        v[k]=min(v[i+1],v[i]);
                        k++;
                    }
                    else {
                        if(abs(v[i]-v[i+1])>d) {
                            flag=0;
                        }
                        v[k]=min(v[i+1],v[i]);
                        k++;
                    }
                }
                d=d*2;
                n=n/2;
            }
            if(flag) {
                cout<<count<<endl;
            }
            else {
                cout<<"-1"<<endl;
            }
        }
    }
}