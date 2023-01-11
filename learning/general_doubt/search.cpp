#include<bits/stdc++.h>
using namespace std;



int search_max(vector<int> &a,vector<int> &b,int index) {
    int l=index+1,h=a.size()-1;
    while(l<h) {
        int mid=(l+h)/2;
        if(a[mid]>b[mid-1]) {
            h=mid-1;
        }
        else if(a[mid]<=b[mid-1]) {
            l=mid+1;
        }
    }
    if(a[l]<=b[l-1]) {
        return l;
    }
    if(a[l]>b[l]) {
        return l-1;
    }

    return a.size()-1;
}

int main() {
    vector<int> a={10,20,30,40};
    vector<int> b={10,20,30,40};
    vector<int> ans;
    for(int i=0;i<a.size()-1;i++) {
        int k=search_max(a,b,i)-1;
        // if(k==a.size()-1) {
        //     ans.push_back(b[k]-a[i]);
        // }
        // else {
        //     ans.push_back(b[k]-a[i]);
        // }
        ans.push_back(k);
    }
    for(int i=0;i<ans.size();i++) {
        cout<<ans[i]<<" ";
    }
}