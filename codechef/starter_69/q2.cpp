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
        int n;
        cin>>n;
        string s;
        cin>>s;
        int count_one=0;
        vector<int> v;
        for(int i=0;i<2*n;i++) {
            if(s[i]=='1') {
                v.push_back(i);
                count_one++;
            }
        }
        if(count_one==0 || count_one==2*n) {
            cout<<"-1"<<endl;
        }
        else {
            vector<int> a;
            int j=0;
            for(int i=0;j<n && i<count_one;i++) {
                a.push_back(v[i]);
                j++;
            }
            if(j<n) {
                for(int i=0;j<n && i<2*n;i++) {
                    if(s[i]=='0') {
                        a.push_back(i);
                        j++;
                    }
                }
            }
            for(int i=0;i<n;i++) {
                cout<<a[i]+1<<" ";
            }
            cout<<endl;
        }
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}