#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
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
        int n,k;
        cin>>n>>k;
        unordered_map<int,int> m;
        vector<int> a;
        for(int i=0;i<n;i++) {
            int p;
            cin>>p;
            a.push_back(p);
            m[p]++;
        }
        vector<int> b;
        for(int i=0;i<n;i++) {
            int p;
            cin>>p;
            b.push_back(p);
        }
        if(m.size()<k) {
            cout<<"-1"<<endl;
        }
        else {
            // sort(b.begin(),b.end());
            unordered_map<int,vector<int>> m1;
            for(int i=0;i<n;i++) {
                m1[a[i]].push_back(b[i]);
            }
            vector<int> v1;
            for(auto i:m1) {
                vector<int> v=i.second;
                sort(v.begin(),v.end());
                v1.push_back(v[0]);
            }
            sort(v1.begin(),v1.end());
            ll sum=0;
            for(int i=0;i<k;i++) {
                sum+=v1[i];
            }
            cout<<sum<<endl;
        }
    }   
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}