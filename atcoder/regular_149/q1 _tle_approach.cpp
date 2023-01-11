#include<bits/stdc++.h>
using namespace std;

bool check_divisiblity(vector<int> v,int m) {
    int n=v.size();
    long p=0;
    int r,q;
    for(int i=0;i<n;i++) {
        p=p*10+v[i];
        if(p>=m) {
            int r=p%m;
            p=r;
        }
    }
    if(p==0) {
        return true;
    }
    else {
        return false;
    }
}

int main() {
    int n,m;
    cin>>n>>m;
    vector<int> ans;
    for(int i=1;i<=9;i++) {
        vector<int> p;
        p.push_back(i);
        int count=0;
        while(count<n) {
            if(check_divisiblity(p,m)) {
                ans=p;
            }
            p.push_back(i);
            count++;
        }
    }
    
    if(ans.size()==0) {
        cout<<"-1";
    }
    else {
        for(int i=0;i<ans.size();i++) {
            cout<<ans[i];
        }
    }
}