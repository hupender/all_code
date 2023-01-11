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
        int n,m,x,y;
        cin>>n>>m>>x>>y;
        if (n==1 || m==1) {
            cout<<"1 1 "<<n<<" "<<m<<endl;
        }
        else {
            int r1=(x-1)+(y-1);
            int r2=(n-x)+(y-1);
            int r3=(n-x)+(m-y);
            int r4=(x-1)+(m-y);
            int r=max(r1,max(r2,max(r3,r4)));
            if(r==r1 || r==r3) {
                cout<<"1 1 "<<n<<" "<<m<<endl;
            }
            else if(r=r2 || r==r4) {
                cout<<n<<" 1 1 "<<m<<endl;
            }
        }
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}