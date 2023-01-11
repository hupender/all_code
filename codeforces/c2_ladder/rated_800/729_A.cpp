#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
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
        int odd_count=0;
        for(int i=0;i<2*n;i++) {
            int k;
            cin>>k;
            if(k%2!=0) {
                odd_count++;
            }
        }
        if(odd_count==n) {
            cout<<"Yes"<<endl;
        }
        else {
            cout<<"No"<<endl;
        }

    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<"endl";
    #endif
}