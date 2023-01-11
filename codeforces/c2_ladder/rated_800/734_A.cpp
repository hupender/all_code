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
        int q=n/3;
        int r=n%3;
        if(r==1) {
            cout<<q+1<<" "<<q<<endl;
        }
        else if(r==2) {
            cout<<q<<" "<<q+1<<endl;
        }
        else {
            cout<<q<<" "<<q<<endl;
        }
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<"endl";
    #endif
}