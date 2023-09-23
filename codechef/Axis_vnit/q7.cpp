#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    int n,m;
    cin>>n>>m;
    vector<vector<char>> v;
    for(int i=0;i<n;i++) {
        vector<char> v1;
        for(int j=0;j<m;j++) {
            char c;
            cin>>c;
            v1.push_back(c);
        }
        v.push_back(v1);
    }
    vector<vector<int>> res(n,vector<int>(m,0));
    for(int i=0;i<n;i++) {
        if(v[i][0]=='*') {
            res[i][0]=1;
        }
        else if(v[i][0]=='#') {
            res[i][0]=-1;
        }
    }
    for(int j=1;j<m;j++) {
        for(int i=0;i<n;i++) {
            if(v[i][j]=='#') {
                res[i][j]=-1;
            }
            else {
                int val1=-1,val2=-1,val3=-1;
                if(i-1>=0) {
                    val1=res[i-1][j-1];
                }
                if(i+1<n) {
                    val2=res[i+1][j-1];
                }
                val3=res[i][j-1];
                int m=max({val1,val2,val3});
                if(v[i][j]=='*') {
                    if(m==-1) {
                        res[i][j]=m;
                    }
                    else {
                        res[i][j]=m+1;
                    }
                }
                else {
                    res[i][j]=m;
                }
            }
        }
    }
    int ans=-1;
    for(int i=0;i<n;i++) {
        ans=max(ans,res[i][m-1]);
    }
    cout<<ans<<endl;
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