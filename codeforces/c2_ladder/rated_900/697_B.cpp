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
    for(int x=1;x<=t;x++) {
        int n;
        cin>>n;
        // if(t==10000 && x==1902) {
        //     cout<<n;
        // }
        if(n<2020) {
            cout<<"No"<<endl;
        }
        else {
            // if(n%2020==0 || n%2020==1 || n%2021==0) {
            //     cout<<"Yes"<<endl;
            // }
            // else {
            //     cout<<"No"<<endl;
            // }
            int q=n/2020;
            int r=n%2020;
            if(r<=q) {
                cout<<"Yes"<<endl;
            }
            else {
                cout<<"No"<<endl;
            }
        }
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}