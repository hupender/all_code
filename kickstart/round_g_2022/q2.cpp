#include<bits/stdc++.h>
using namespace std;
float get_distance(int a,int b) {
    float ans=1.0*sqrt(a*a+b*b);
    return ans;
}
int main() {
    freopen("inp.txt","r",stdin);
    freopen("out.txt","w",stdout);
    int t;
    cin>>t;
    for(int z=1;z<=t;z++) {
        int rs,rh;
        cin>>rs>>rh;
        int n;
        cin>>n;
        vector<float> v1;
        for(int i=0;i<n;i++) {
            int a,b;
            cin>>a>>b;
            v1.push_back(get_distance(a,b));
        }
        int m;
        cin>>m;
        vector<float> v2;
        for(int i=0;i<m;i++) {
            int a,b;
            cin>>a>>b;
            v2.push_back(get_distance(a,b));
        }
        if(m==0) {
            int count=0;
            for(int i=0;i<n;i++) {
                if(v1[i]<=rs+rh) {
                    count++;
                }
            }
            cout<<"Case #"<<z<<": "<<count<<" 0"<<endl;
        }
        else if(n==0) {
            int count=0;
            for(int i=0;i<n;i++) {
                if(v2[i]<=rs+rh) {
                    count++;
                }
            }
            cout<<"Case #"<<z<<": 0 "<<count<<endl;
        }
        else {
            int ans1=0,ans2=0;
            sort(v1.begin(),v1.end());  
            sort(v2.begin(),v2.end());
            if(v1[0]<v2[0]) {
                for(int i=0;i<v1.size() && v1[i]<v2[0];i++) {
                    if(v1[i]<=rs+rh) {
                        ans1++;
                    }
                }
            }
            else {
                for(int i=0;i<v2.size() && v2[i]<v1[0];i++) {
                    if(v2[i]<=rs+rh) {
                        ans2++;
                    }
                }
            }
            cout<<"Case #"<<z<<": "<< ans1 <<" "<<ans2<<endl;
        }
    }
}