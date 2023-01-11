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
        int a=1;
        int count=0;
        while(n>0) {
            n-=a;
            count++;
            a+=2;
        }
        cout<<count<<endl;
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<"endl";
    #endif
}