#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v;
        int count=0;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            if(k%2==0) {
                count++;
            }
        }
        if(count==n) {
            cout<<"0"<<endl;
        }
        else {
            cout<<count<<endl;
        }
    }
}