#include<bits/stdc++.h>
using namespace std;
void insertion_sort(vector<int> &v,int k) {
    if(k>=v.size()) {
        return;
    }
    int j=k-1;
    int key=v[k];
    while(j>=0 && v[j]>key) {
        v[j+1]=v[j];
        j--;
    }
    v[j+1]=key;
    insertion_sort(v,k+1);
}

int main() {
    int n;
    cin>>n;
    vector<int> v;
    for (int i = 0; i < n; i++) {
        int t;
        cin>>t;
        v.push_back(t);
    }
    insertion_sort(v,1);
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
}