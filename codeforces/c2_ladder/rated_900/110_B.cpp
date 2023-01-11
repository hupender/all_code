#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
int gcd(int a,int b) {
    if(b==0) {
        return a;
    }
    return gcd(b,a%b);
}
int main() {
    #ifndef ONLINE_JUDGE
        clock_t clock_begin = clock();
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    ios::sync_with_stdio(false);
    cin.tie(0);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        vector<int> v;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            v.push_back(k);
        }
        int count=0;
        for(int i=0;i<n-1;i++) {
            for(int j=i+1;j<n;j++) {
                int g=gcd(v[i],2*v[j]);
                if(g>1) {
                    count++;
                }
                else {
                    g=gcd(2*v[i],v[j]);
                    if(g>1) {
                        count++;
                    }
                }
            }
        }
        cout<<count<<endl;
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}