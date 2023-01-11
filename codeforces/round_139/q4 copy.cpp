#include<bits/stdc++.h>
using namespace std;
int gcd(int x,int y) {
    if(y==0) {
        return x;
    }
    return gcd(y,x%y);
}

unordered_map<int,vector<int>>  get_prime() {
    int mod=10000000;
    vector<bool> visited(mod,false);
    unordered_map<int,vector<int>> m;
    for(int i=2;i<=mod;i++) {
        if(!visited[i]) {
            int n=i;
            int j=2;
            while(n<=mod) {
                visited[n]=true;
                m[n].push_back(i);
                n*=j;
                j++;
            }
        }
    }
    return m;
}

int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    unordered_map<int,vector<int>>m=get_prime();
    for(auto i:m[2]) {
        cout<<i<<" ";
    }
    cout<<endl;
    // int t;
    // cin>>t;
    // while(t--) {
    //     int x,y;
    //     cin>>x>>y;
    //     if(abs(x-y)==1) {
    //         cout<<"-1"<<endl;
    //     }
    //     else {
    //         if(gcd(x,y)>1) {
    //             cout<<"0"<<endl;
    //         }
    //         else {
    //             int diff=abs(x-y);
    //             // int fact=get_min_fact(diff);
    //             // int r=x%fact;
    //             // cout<<fact-r<<endl;
    //         }
    //     }
    // }
}