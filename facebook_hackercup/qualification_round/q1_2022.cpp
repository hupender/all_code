#include<bits/stdc++.h>
using namespace std;
int main() {
    // ios_base::sync_with_stdio(false);
    // cin.tie(NULL);
    
    // freopen("input.txt", "r", stdin);
    // freopen("output.txt", "w", stdout);

    int t;
    cin>> t;
    
    for(int x=1;x<=t;x++) {
        int n,k,flag=1;
        cin>> n,k;
        unordered_map<int,int> m;
        for(int i=0;i<n;i++) {
            int p;
            cin>>p;
            m[p]++;
            if(m[p]>2) {
                flag=0;
            }
            // cout<<"flag is"<<flag<<endl;
        }
        if(n>2*k) {
            flag=0;
        }
        if(flag==0) {
            cout << "Case #" << x << ": "<< "NO" << endl;
        }
        else {
            cout << "Case #" << x << ": "<< "YES" << endl;
        }
        
    }
}