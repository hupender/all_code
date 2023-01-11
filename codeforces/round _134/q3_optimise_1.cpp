#include<bits/stdc++.h>
using namespace std;
int search_min(vector<int> &v,int k) {
    int l=0,h=v.size()-1,ind=-1;
    while(l<h) {
        int mid=(l+h)/2;
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
    }
    if(ind!=-1){
        return ind;
    }
    if(v[l]>=k) {
        return l;
    }
    if(v[l+1]>k) {
        return l+1;
    }
    return 0;
}

int main() {

    // freopen("input.txt","r",stdin);
    // freopen("output.txt","w",stdout);
    
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a(n);
        vector<int> b(n);
        for(int i=0;i<n;i++) {
            cin>>a[i];
        }
        for(int i=0;i<n;i++) {
            cin>>b[i];
        }
        vector<int> dmin;
        vector<int> dmax;
        for(int i=0;i<n;i++) {
            int t=search_min(b,a[i]);
            dmin.push_back(b[t]-a[i]);
        }
        int ind;
        for(int i=0;i<n;i++) {
            int flag=0;
            for(int j=i+1;j<n;j++) {
                if(a[j]>b[j-1]) {
                    ind=j-1;
                    flag=1;
                    break;
                }
            }
            if(flag==0) {
                ind=n-1;
            }
            while(i<=ind) {
                dmax.push_back(b[ind]-a[i]);
                i++;
            }
            i--;
        }
        if(dmax.size()<n) {
            dmax.push_back(b[n-1]-a[n-1]);
        }
        
        for(int i=0;i<n;i++) {
            cout<<dmin[i]<<" ";
        }
        cout<<endl;

        for(int i=0;i<dmax.size();i++) {
            cout<<dmax[i]<<" ";
        }
        cout<<endl;
    }
}