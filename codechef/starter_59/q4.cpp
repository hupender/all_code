#include<bits/stdc++.h>
using namespace std;
int main() {
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> a;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            a.push_back(k);
        }
        int m;
        cin>>m;
        long long sum_b=0;
        for(int i=0;i<m;i++) {
            int k;
            cin>>k;
            if(k>0) {
                sum_b+=k;
            }
        }
        long long largest_sum=0;
        long long prefix_sum=0;
        for(int i=0;i<n;i++) {
            prefix_sum+=a[i];
            largest_sum=max(largest_sum,prefix_sum);
        }
        long long suffix_sum=0;
        for(int i=n-1;i>=0;i--) {
            suffix_sum+=a[i];
            largest_sum=max(largest_sum,suffix_sum);
        }

        cout<< largest_sum+sum_b<<endl;

    }
}