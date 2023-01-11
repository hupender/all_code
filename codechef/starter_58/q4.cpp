#include<bits/stdc++.h>
using namespace std;
bool check_prime(int n) {
    for(int i=2;i*i<=n;i++) {
        if(n%i==0) {
            return false;
        }
    }
    return true;
}
map<int,int> get_prime_factor(int a) {
    map<int,int> m;
    if(check_prime(a)) {
        m[a]++;
        return m;
    }
    for(int i=2;(i-1)*(i-1)<a;i++) {
        if(a%i==0) {
            // int count=0;
            while(a%i==0) {
                m[i]++;
                a=a/i;
            }
        }
    }
    if(a>1) {
        m[a]++;
    }
    return m;
}
int main() {
    int t;
    cin>>t;
    while(t--) {
        int a,b;
        cin>>a>>b;
        map<int,int> v1=get_prime_factor(a);
        map<int,int> v2=get_prime_factor(b);
        if(v1.size()!=v2.size()) {
            cout<<"no"<<endl;
        }
        else {
            // unordered_map<float,int> m;
            int flag=1;
            float x;
            x=1.0*v1.begin()->second/v2.begin()->second;
            for(auto i:v1) {
                int k=i.first;
                int p=v2[i.first];
                int q=i.second;
                float z=1.0*q/p;
                if(x!=z) {
                    flag=0;
                    break;
                }
            }
            if(flag) {
                cout<<"yes"<<endl;
            }
            else {
                cout<<"no"<<endl;
            }
        }
    }
}