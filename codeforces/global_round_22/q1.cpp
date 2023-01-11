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
        vector<int> a;
        vector<int> d;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            a.push_back(k);
        }
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            d.push_back(k);
        }
        vector<long long> fire;
        vector<long long> water;
        for(int i=0;i<n;i++) {
            if(a[i]==0) {
                fire.push_back(d[i]);
            }
            else {
                water.push_back(d[i]);
            }
        }
        sort(fire.begin(),fire.end());
        sort(water.begin(),water.end());
        if(fire.size()==0) {
            long long sum=0;
            for(int i=0;i<water.size();i++) {
                sum+=water[i];
            }
            cout<<sum<<endl;
        }
        else if(water.size()==0) {
            long long sum=0;
            for(int i=0;i<fire.size();i++) {
                sum+=fire[i];
            }
            cout<<sum<<endl;
        }
        else if(water.size()>fire.size()) {
            long long sum=water[0];
            int nf=fire.size();
            int nw=water.size();
            for(int i=0;i<nf;i++) {
                sum+=2*fire[i];
            }
            for(int i=nw-1;i>=nw-nf;i--) {
                sum+=2*water[i];
            }
            for(int i=1;i<nw-nf;i++) {
                sum+=water[i];
            }
            cout<<sum<<endl;
        }
        else if(fire.size()>water.size()) {
            long long sum=fire[0];
            int nf=fire.size();
            int nw=water.size();
            for(int i=0;i<nw;i++) {
                sum+=2*water[i];
            }   
            for(int i=nf-1;i>=nf-nw;i--) {
                sum+=2*fire[i];
            }
            for(int i=1;i<nf-nw;i++) {
                sum+=fire[i];
            }
            cout<<sum<<endl;
        }
        else if(fire.size()==water.size()) {
            long long sum=0;
            if(fire[0]>water[0]) {
                sum+=water[0]+2*fire[0];
            }
            else {
                sum+=fire[0]+2*water[0];
            }
            for(int i=1;i<fire.size();i++) {
                sum+=2*fire[i];
            }
            for(int i=1;i<water.size();i++) {
                sum+=2*water[i];
            }
            cout<<sum<<endl;
        }
    }
}