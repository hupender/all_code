#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,q;
        cin>>n>>q;
        vector<long long> v;
        for(int i=0;i<n;i++) {
            long long k;
            cin>>k;
            v.push_back(k);
        }
        vector<vector<int>> freq;
        for(int j=0;j<60;j++) {
            vector<int> prefix_one_count;
            int count=0;
            for(int i=0;i<n;i++) {
                if(v[i]%2==1) {
                    count++;
                }
                prefix_one_count.push_back(count);
                v[i]=v[i]/2;
            }
            freq.push_back(prefix_one_count);
        }
        while(q--) {
            int k,l1,r1,l2,r2;
            cin>>k>>l1>>r1>>l2>>r2;
            int a;
            if(l1-2<0) {
                a=0;
            }
            else {
                a=freq[k][l1-2];
            }
            int b=freq[k][r1-1];   
            int c=freq[k][l2-2];
            int d=freq[k][r2-1];
            int one_between_l1_r1=b-a;          // number of 1's between l1 and r1
            int size1=r1-l1+1;                  // no of elements between l1 and r1 inclusive
            int n1=size1-one_between_l1_r1;     // number of 0's between l1 and r1
            int one_between_l2_r2=d-c;          // num of 1's between l2 and l2
            int size2=r2-l2+1;                  // num of elements l2 and r2 inclusive
            int n2=size2-one_between_l2_r2;     // num of 0's between l2 and r2
            long long res=one_between_l1_r1*n2 + n1*one_between_l2_r2;
            cout<<res<<endl;
        }
    }
}