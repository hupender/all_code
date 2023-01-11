#include<bits/stdc++.h>
using namespace std;

int search(vector<int> v,int k) {
    int l=0,h=v.size()-1,ind=-1;
    while(l<h) {
        int mid=(l+h)/2;
        // cout<<l<<" "<<h<<" "<<mid<<endl;
        if(v[mid]<k) {
            l=mid+1;
        }
        else if(v[mid]>k) {
            h=mid-1;
        }
        else {
            ind=mid;
            break;
        }
        // cout<<l<<" "<<h<<" "<<mid<<endl;
    }
    // cout<<l<<h<<ind<<endl;
    if(ind!=-1){
        return ind;
    }
    // else if(v[l]>=k) {
    //     return l;
    // }
    // else if(v[h]>=k) {
    //     return h;
    // }
    if(v[l]>=k) {
        return l;
    }
    if(v[l+1]>k) {
        return l+1;
    }
    return 0;
}

int main() {
    int n,k;
    cin>>n>>k;
    vector<int> v(n);
    for(int i=0;i<n;i++) {
        cin>>v[i];
    }
    int ans=search(v,k);
    cout<<ans<<endl;
}

/*
5 3 
1 2 4 5 6
*/