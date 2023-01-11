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

// int search_max(vector<int> &a,vector<int> &b,int index) {2
//     int l=index+1,h=a.size()-1;
//     while(l<h) {
//         int mid=(l+h)/2;
//         if(a[mid]>b[mid-1]) {
//             h=mid-1;
//         }
//         else if(a[mid]<=b[mid-1]) {
//             l=mid+1;
//         }
//     }
//     if(a[l]<=b[l-1]) {
//         return l;
//     }
//     if(a[l]>b[l-1]) {
//         return l-1;
//     }

//     return a.size()-1;
// }

int main() {

    #ifndef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif

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
        // int k=0;
        for(int i=0;i<n;i++) {
            int t=search_min(b,a[i]);
            // int p=search_max(a,b,i);
            // dmax.push_back(b[p]-a[i]);
            dmin.push_back(b[t]-a[i]);
            // k++;
        }
        int ind;
        for(int i=0;i<n;i++) {
            // int t=search_min(b,a[i]);
            // int p=search_max(a,b,i);
            // dmax.push_back(b[p]-a[i]);
            // dmin.push_back(b[t]-a[i]);
            // k++;
            for(int j=i+1;j<n;j++) {
                if(a[j]>b[j-1]) {
                    ind=j-1;
                    // dmax.push_back(b[ind]-a[i]);
                    break;
                }
            }
            // i++;
            while(i<=ind) {
                dmax.push_back(b[ind]-a[i]);
                i++;
            }
            i--;
        }
        dmax.push_back(b[n-1]-a[n-1]);
        for(int i=0;i<n;i++) {
            cout<<dmin[i]<<" ";
        }
        cout<<endl;

        for(int i=0;i<n;i++) {
            cout<<dmax[i]<<" ";
        }
        cout<<endl;
    }
}