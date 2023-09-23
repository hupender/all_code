#include<bits/stdc++.h>
using namespace std;
#define endl "\n"
#define ll long long int
void solve() {
    vector<vector<int>> v(10,vector<int>(7,1));
    for(int i=0;i<10;i++) {
        if(i==0) {
            v[i][6]=0;
        }
        if(i==1) {
            for(int j=0;j<7;j++) {
                if(j!=1 && j!=2) {
                    v[i][j]=0;
                }
            }
        }
        if(i==2) {
            v[i][2]=0;
            v[i][5]=0;
        }
        if(i==3) {
            v[i][4]=0;
            v[i][5]=0;
        }
        if(i==4) {
            v[i][0]=0;
            v[i][3]=0;
            v[i][4]=0;
        }
        if(i==5) {
            v[i][1]=0;
            v[i][4]=0;
        }
        if(i==6) {
            v[i][1]=0;
        }
        if(i==7) {
            v[i][3]=0;
            v[i][4]=0;
            v[i][5]=0;
            v[i][6]=0;
        }
        if(i==8) {
            continue;
        }
        if(i==9) {
            v[i][4]=0;
        }
    }
    int x,y;
    cin>>x>>y;
    int count=0;
    for(int i=0;i<7;i++) {
        if(v[x][i]!=v[y][i]) {
            count++;
        }
    }
    cout<<count<<endl;
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