#include<bits/stdc++.h>
using namespace std;
bool is_sorted(vector<int> v) {
    int  size=v.size();
    for(int i=0;i<size-1;i++) {
        if(v[i]>v[i+1]) {
            return false;
        }
    }
    return true;
}
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,k;
        cin>>n>>k;
        vector<int> sum;
        for(int i=0;i<k;i++) {
            int k;
            cin>>k;
            sum.push_back(k);
        }
        vector<int> v;
        for(int i=0;i<k-1;i++) {
            v.push_back(sum[i+1]-sum[i]);
        }
        if(is_sorted(v)) {
            int size=n-k+1;
            if(v.size()==0) {
                cout<<"Yes"<<endl;
            }
            else {
                long long first_term=v[0];
                int first_sum=sum[0];
                if(first_term*size>=first_sum) {
                    cout<<"Yes"<<endl;
                }
                else {
                    cout<<"No"<<endl;
                }
            }   
        }
        else {
            cout<<"No"<<endl;
        }
    }
}