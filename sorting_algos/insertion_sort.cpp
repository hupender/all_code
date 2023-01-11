#include<bits/stdc++.h>
using namespace std;

void insertion_sort(vector<int> &v) {
    int n=v.size(),key;
    for(int i=1;i<n;i++) {
        key=v[i];
        int j=i-1;
        while(j>=0 && key<v[j]) {
            v[j+1]=v[j];
            j--;
        }
        v[j+1]=key;
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
    insertion_sort(v);
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
}