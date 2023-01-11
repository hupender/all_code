#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n;
    cin>>n;
    if(n==2) {
        cout<<"-1"<<endl;
    }
    else {
        if(n%2==0) {
            int a[n][n];
            int val=1;
            int val2=4;
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(i%2==0) {
                        a[i][j]=val;
                        val+=2;
                    }
                    else {
                        if(i==n-1 && j==n-1) {
                            a[i][j]=2;
                        }
                        else {
                            a[i][j]=val2;
                            val2+=2;
                        }
                    }
                }
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
        }
        else {
            int a[n][n];
            int val=1;
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(i%2==0) {
                        if(val<=n*n) {
                            a[i][j]=val;
                            val+=2;
                        }
                        else {
                            val=2;
                            a[i][j]=val;
                            val+=2;
                        }  
                    }
                }
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    if(i%2!=0) {
                        a[i][j]=val;
                        val+=2;
                    }
                }
            }
            for(int i=0;i<n;i++) {
                for(int j=0;j<n;j++) {
                    cout<<a[i][j]<<" ";
                }
                cout<<endl;
            }
        }
    }
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
        solve();
    }
    #ifndef ONLINE_JUDGE
        clock_t clock_end = clock();
        cout<<"Executed In : "<<double(clock_end-clock_begin)/CLOCKS_PER_SEC*1000<<" ms"<<endl;
    #endif
}