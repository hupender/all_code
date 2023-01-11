#include<bits/stdc++.h>
using namespace std;

int get_max(vector<int> v) {
    int m=0;
    for(int i=0;i<v.size();i++) {
        m=max(m,v[i]);
    }
    return m;
}

void count_sort(vector<int> &v) {
    
    int n=v.size();
    int m=get_max(v);
    vector<int> count(m+1,0);
    // vector<int> count;
    // for(int i=0;i<m;i++) {
    //     count[i]=0;
    // }
    for(int i=0;i<n;i++) {
        count[v[i]]++;
    }
    int i=0,j=0;
    while(i<=m) {
        if(count[i]>0) {
            count[i]--;
            v[j]=i;
            j++;
        }
        else {
            i++;
        }
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
    count_sort(v);
    for(int i=0;i<n;i++) {
        cout<<v[i]<<" ";
    }
}