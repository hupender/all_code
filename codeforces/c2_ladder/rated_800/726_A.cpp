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
        long sum=0;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            sum+=k;
        }
        if(sum==n) {
            cout<<"0"<<endl;
        }
        else if(sum<n) {
            cout<<"1"<<endl;
        }
        else {
            cout<<sum-n<<endl;
        }
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<"endl";
    #endif
}