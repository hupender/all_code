#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,x;
        cin>>n>>x;
        vector<int> v;
        v.push_back(x);
        // v[0]=x;
        // v[n-1]=1;
        if(n%x==0) {
            int p=n/x;
            vector<pair<int,int>> fact;
            int f=2;
            while(p>1) {
                if(p%f==0) {
                    int count=0;
                    while(p%f==0) {
                        p=p/f;
                        count++;
                    }
                    fact.push_back({f,count});
                }
                f++;
            }
            int j=0;
            for(int i=2;i<n;i++) {
                if(i%x==0) {
                    int a=fact[j].first;
                    x=a*x;
                    fact[j].second--;
                    v.push_back(x);
                    if(fact[j].second==0) {
                        j++;
                    }
                }
                else {
                    v.push_back(i);
                }
            }
            v.push_back(1);
            for(int i=0;i<n;i++) {
                cout<<v[i]<<" ";
            }
            cout<<endl;
        }   
        else {
            cout<<"-1"<<endl;
        }
    }
}