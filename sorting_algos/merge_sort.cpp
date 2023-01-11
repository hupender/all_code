#include<bits/stdc++.h>
using namespace std;

void merge(vector<int> &v,int l,int m,int h) {
    vector<int> v1;
    vector<int> v2;
    for(int i=l;i<=m;i++) {
        v1.push_back(v[i]);
    }
    for(int i=m+1;i<=h;i++) {
        v2.push_back(v[i]);
    }
    int i=0,j=0,k=l;
    while(i<v1.size() && j<v2.size()) {
        if(v1[i]<v2[j]) {
            v[k]=v1[i];
            i++;
            k++;
        }
        else {
            v[k]=v2[j];
            j++;
            k++;
        }
    }
    if(i==v1.size()) {
        for(int p=j;p<v2.size();p++) {
            v[k]=v2[p];
            k++;
        }
    }
    if(j==v2.size()) {
        for(int p=i;p<v1.size();p++) {
            v[k]=v1[p];
            k++;
        }
    }
}

void merge_sort(vector<int> &v,int l,int h) {
    int m=(l+h)/2;
    if(l==h) {
        return;
    }
    if(l<=h) {
        merge_sort(v,l,m);
        merge_sort(v,m+1,h);
        merge(v,l,m,h);
    }
}

int main() {
    int n;
    cin>>n;
    vector<int> v;
    for(int i=0;i<n;i++) {
        int t;
        cin>>t;
        v.push_back(t);
    }
    merge_sort(v,0,n-1);
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
}