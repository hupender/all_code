#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int n;
    cin>>n;
    long long int t;
    cin>>t;
    vector<int> v;
    long long int sum=0;
    for(int i=0;i<n;i++) {
        int k;
        cin>>k;
        sum+=k;
        v.push_back(k);
    }
    t%=sum;
    int count,time;
    for(int i=0;i<n;i++) {
        if(t>=v[i]) {
            t-=v[i];
        }
        else {
            count=i+1;
            time=t;
            break;
        }
    }
    cout<<count<<" "<<time<<endl;
}