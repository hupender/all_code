#include<bits/stdc++.h>
using namespace std;

int partition(vector<int> &v,int low ,int high) {
    int pivot=v[high];
    int j=low-1;
    for(int i=low;i<high;i++) {
        if(v[i]<pivot) {
            j++;
            swap(v[i],v[j]);
        }
    }
    swap(v[j+1],v[high]);
    return j+1;
}


void quick_sort(vector<int> &v,int low,int high) {
    if(low<high) {
        int pi;
        pi=partition(v,low,high);
        quick_sort(v,low,pi-1);
        quick_sort(v,pi+1,high);
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
    quick_sort(v,0,n-1);
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
}