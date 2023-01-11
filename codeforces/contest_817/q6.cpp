#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("input6.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int n,m;
        cin>>n>>m;
        vector<string> a;
        for(int i=0;i<n;i++) {
            string s;
            cin>>s;
            a.push_back(s);
        }
        int b[n][m];
        memset(b,0,sizeof(b));

        // cout<< "input is "<<endl;
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) {
        //         cout<<a[i][j]<<" ";
        //     }
        //     cout<<endl;
        // }
        int count=0;
        int c[n][m];
        memset(c,0,sizeof(c));
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {  
                if(a[i][j]=='*') {
                    count++;
                    b[i][j]++;
                    if(j-1>=0 && a[i][j]==a[i][j-1])  {
                        c[i][j]++;
                        b[i][j]++;
                    }
                    if(j+1<m && a[i][j]==a[i][j+1]) {
                        c[i][j]++;
                        b[i][j]++;
                    }
                    if(i-1>=0) {
                        if(a[i][j]==a[i-1][j]) {
                            c[i][j]++;
                            b[i][j]++;
                        }
                        if(j-1>=0 && a[i][j]==a[i-1][j-1]) {
                            b[i][j]++;
                        }
                        if(j+1<m && a[i][j]==a[i-1][j+1]) {
                            b[i][j]++;
                        }
                    }
                    if(i+1<n) {
                        if(a[i][j]==a[i+1][j]) {
                            c[i][j]++;
                            b[i][j]++;
                        }
                        if(j-1>=0 && a[i][j]==a[i+1][j-1]) {
                            b[i][j]++;
                        }
                        if(j+1<m && a[i][j]==a[i+1][j+1]) {
                            b[i][j]++;
                        }
                    }
                }
            }           
        }

        // cout<< "count vector is "<<endl;
        // for(int i=0;i<n;i++) {
        //     for(int j=0;j<m;j++) {
        //         cout<<b[i][j]<<" ";
        //     }
        //     cout<<endl;
        // } 

        int flag=1;
        for(int i=0;i<n;i++) {
            for(int j=0;j<m;j++) {
                if(b[i][j]!=3 && b[i][j]!=0 || b[i][j]==3 && c[i][j]==0 || count%3!=0) {
                    flag=0;
                }
            }
        }
        if(flag==1) {
            cout<<"YES"<<endl;
            }
        else {
            cout<<"NO"<<endl;
        }
    }
}