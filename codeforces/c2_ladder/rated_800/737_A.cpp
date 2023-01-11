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

    cout.setf(ios::fixed);
    cout.setf(ios::showpoint);
    cout.precision(9);
    int t;
    cin>>t;
    while(t--) {
        int n;
        cin>>n;
        double sum=0;
        int m=INT_MIN;
        for(int i=0;i<n;i++) {
            int k;
            cin>>k;
            sum+=k;
            m=max(m,k);
        }
        sum-=m;
        sum/=(n-1);
        sum+=m;
        cout<<sum<<endl;
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<"endl";
    #endif
}