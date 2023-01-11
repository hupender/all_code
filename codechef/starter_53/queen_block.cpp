#include<bits/stdc++.h>
using namespace std;
int main() {
    #ifndef ONLINE_JUDGE
        freopen("inp.txt","r",stdin);
        freopen("out.txt","w",stdout);
    #endif
    int t;
    cin>>t;
    while(t--) {
        int a,b;
        cin>>a>>b;
        vector<vector<int>> v(8,vector<int>(8,0));
        v[a-1][b-1]=1;
        if(a==1 && b==1) {
            v[2][1]=2;
        }
        else if(a==1 && b==8) {
            v[2][6]=2;
        }
        else if(a==8 && b==1) {
            v[5][1]=2;
        }
        else if(a==8 && b==8) {
            v[6][5]=2;
        }
        else if(a==1 && b>1 && b<8) {
            v[2][b-2]=2;
            v[2][b]=2;
        }
        else if(a>1 && a<8 && b==1) {
            v[a-2][2]=2;
            v[a][2]=2;
        }
        else if(a>1 && a<8 && b==8) {
            v[a-2][5]=2;
            v[a][5]=2;
        }
        else if(a==8 && b>1 && b<8) {
            v[5][b-2]=2;
            v[5][b]=2;
        }

        else if(a==2 && b>1 && b<8) {
            if(b-2>0) {
                v[a-2][b-3]=2;
                v[a+2][b]=2;
            }
            else {
                v[a-2][b+1]=2;
                v[a+2][b-2]=2;
            }
        }
        else if(a==7 && b>1 && b<8) {
            if(b-2>0) {
                v[a-4][b]=2;
                v[a][b-3]=2;
            }
            else {
                v[a-4][b-2]=2;
                v[a][b+1]=2;
            }
        }
        else if(a>2 && a<7 && b==2) {
            if(a-3>0) {
                v[a-4][b-2]=2;
                v[a][b+1]=2;
            }
            else {
                v[a-2][b+1]=2;
                v[a+2][b-2]=2;
            }
        }
        else if(a>2 && a<6 && b==7) {
            if(a-3>0) {
                v[a-4][b]=2;
                v[a][b-3]=2;
            }
            else {
                v[a-2][b-3]=2;
                v[a+2][b]=2;
            }
        }
        else {
            v[a+1][b]=2;
            v[a-3][b-2]=2;
        }
        for(int i=0;i<8;i++) {
            for(int j=0;j<8;j++) {
                cout<<v[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl<<endl;
    }
}