#include<bits/stdc++.h>
using namespace std;
int main() {
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
        vector<pair<int,int>> m;
        for(int i=0;i<n-1;i++) {
            if(v[i]<=v[i+1]) {
                int ind=i;
                while(v[i+1]>=v[i] && i<n-1) {
                    i++;
                }
                m.push_back({1,i-ind+1});
                i--;
            }
            else {
                int ind=i;
                while(v[i+1]<=v[i] && i<n-1) {
                    i++;
                }
                m.push_back({0,i-ind+1});
                i--;
            }
        }
        int count=n;
        for(int i=0;i<m.size();i++) {
            int x=m[i].second;
            count+=(x*(x-1))/2;
        }
        for(int i=0;i<m.size()-1;i++) {
            if(m[i].first==0 && m[i+1].first==1) {
                int p=m[i+1].second-1;
                int q=m[i].second-1;
                count+=p*q;
            }
        }
        cout<<count<<endl;
    }
}