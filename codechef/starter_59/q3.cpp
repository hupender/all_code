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
        vector<int> v1;
        vector<int> v2;
        int trans=0;
        for(int i=0;i<n;i++) {
            int p=v[i];
            if(trans%2==0) {
                v1.push_back(p);
            }
            else {
                v2.push_back(p);
            }
            i++;
            while(v[i]<p && i<n) {
                if(trans%2==0) {
                    v1.push_back(v[i]);
                }
                else {
                    v2.push_back(v[i]);
                }
                i++;
            }
            i--;
            trans++;
        }
        if(v1.size()==0 || v2.size()==0) {
            cout<<"-1";
        }
        else {
            int n1=v1.size();
            cout<<n1<<endl;
            for(int i=0;i<n1;i++) {
                cout<<v1[i]<<" ";
            }
            cout<<endl;
            int n2=v2.size();
            cout<<n2<<endl;
            for(int i=0;i<n2;i++) {
                cout<<v2[i]<<" ";
            }
            cout<<endl;
        }
    }
}