#include<bits/stdc++.h>
using namespace  std;
int main() {
    freopen("inp.txt","r",stdin);
    int n;
    vector<int> a;
    vector<int> b;
    cin>>n; 
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        a.push_back(k);
    }
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        b.push_back(k);
    }
    int flag=1;
    int ind;
    for(int i=0;i<n;i++) {
        if(a[i]!=b[i]) {
            flag=0;
            ind=i;
            break;
        }
    }
    if(flag) {
        cout<<"same"<<endl;
    }
    else {
        cout<<"diff"<<endl;
        cout<<ind<<endl;
    }
}