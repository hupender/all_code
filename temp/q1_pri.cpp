#include<bits/stdc++.h>
using namespace std;
int main() {
    int x;
    cin>>x;
    int val=10000;
    vector<int> v;
    while(x>0 && val>0) {
        if(x<val) {
            v.push_back(x);
            x=0;
        }
        if(x>=val) {
            v.push_back(val);
            x=x-val;
            val--;
        }
    }
    if(x>0) {
        cout<<"-1"<<endl;
    }
    else {
        for(int i=0;i<v.size();i++) {
            cout<<v[i]<<" ";
        }
        cout<<endl;
    }
}